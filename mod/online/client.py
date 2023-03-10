import asyncio
import socketio
import PySimpleGUI as sg
import locale
from pymem.process import list_processes
import sys

if __name__ == '__main__':
    current_dir = sys.path[0]
    back_to_root = "\\".join(i for i in current_dir.split('\\')[:-2])
    print(back_to_root)
    sys.path.append(back_to_root+"\\tools")
    sys.path.append(back_to_root)
from tools import ram_access
from tools import ascendancy_lib

game = ram_access.Game()

sio = socketio.AsyncClient()

all_processes = []
simple_processes = []

complex_process_tree = sg.TreeData() # regroup processes by name
simple_tree_processes = sg.TreeData() # regroup processes by name

def get_processes():
    global all_processes, simple_processes, complex_process_tree, simple_tree_processes

    all_processes = []
    simple_processes = []
    
    complex_process_tree = sg.TreeData() # regroup processes by name
    simple_tree_processes = sg.TreeData() # regroup processes by name
    
    for process in list_processes():
        name = process.szExeFile.decode(locale.getpreferredencoding()).lower()
        name_id = name+" "+str(all_processes.count(name))

        all_processes.append(name)
        
        if "dos" in name:
            simple_processes.append(name)
            
            if simple_processes.count(name) > 1:
                simple_tree_processes.Insert(name, process.th32ProcessID, name_id, values=[process.th32ProcessID])
            else:
                simple_tree_processes.Insert('', name, name, values=[name])
                simple_tree_processes.Insert(name, process.th32ProcessID, name_id, values=[process.th32ProcessID])
        
        if all_processes.count(name) > 1:
            complex_process_tree.Insert(name, process.th32ProcessID, name_id, values=[process.th32ProcessID])
        else:
            complex_process_tree.Insert('', name, name, values=[name])
            complex_process_tree.Insert(name, process.th32ProcessID, name_id, values=[process.th32ProcessID])

partys = []

get_processes()

layout_simple_choose_process = [
    [sg.Text('Choose a process')],
    [sg.Tree(data=simple_tree_processes, headings=['Process'], num_rows=20, col0_width=20, key='process')],
    [sg.Button('OK'), sg.Button('Cancel'), sg.Button('Refresh'), sg.Button('Manual')]
]

async def event_simple_choose_process(event: str, values: dict):
    if event.startswith('OK') and len(values['process'])>0:
        game.selected_app(values['process'][0])
        game.init_address()
        switch_layout(2)
    elif event.startswith('Cancel'):
        window.close()
    elif event.startswith('Refresh'):
        get_processes()
        window['process'].update(values=simple_tree_processes)
    elif event.startswith('Manual'):
        switch_layout(1)

layout_complex_choose_process = [
    [sg.Text('Choose a process')],
    [sg.Tree(data=complex_process_tree, headings=['Process'], num_rows=20, col0_width=20, key='process')],
    [sg.Button('OK'), sg.Button('Cancel'), sg.Button('Refresh'), sg.Button('Auto')]
]

async def event_complex_choose_process(event: str, values: dict):
    if event.startswith('OK') and len(values['process0'])>0:
        game.selected_app(values['process0'][0])
        switch_layout(2)
    elif event.startswith('Cancel'):
        window.close()
    elif event.startswith('Refresh'):
        get_processes()
        window['process0'].update(values=complex_process_tree)
    elif event.startswith('Auto'):
        switch_layout(0)

layout_server_connect = [
    [sg.Text('Enter server address "ip:port"')],
    [sg.Input(key='server')],
    [sg.Button('OK'), sg.Button('Cancel')]
]

async def event_server_connect(event: str, values: dict):
    if event.startswith('OK'):
        await sio.connect("http://"+values['server'])
        await sio.emit('get parties')
        switch_layout(3)
    elif event.startswith('Cancel'):
        switch_layout(0)

layout_choose_party = [
    [sg.Text('Choose a party')],
    [sg.Table(values=partys,headings=["id", "player num", "day"], size=(20, 3), key='party', ), sg.Button('Create party')],
    [sg.Input(key='party')],
    [sg.Button('OK'), sg.Button('Cancel')]
]

async def event_choose_party(event: str, values: dict):
    if event.startswith('Create party'):
        await sio.emit('create party')
        races = game.get_all_race()
        for i in range(len(races)):
            await sio.emit("set race", data=[ascendancy_lib.Struct_to_bytes(races[i]), i])
    elif event.startswith('OK') and len(values['party'])>0:
        await sio.emit('join party', values['party'])
        await sio.emit("get all race")
        window['players'].update(value=partys[values['party']][2])
        switch_layout(4)
    elif event.startswith('Cancel'):
        window.close()

layout_in_game = [
    [sg.Text('In game')],
    [sg.Text("number of players: "), sg.Text("0", key='players')],
    [sg.Button('OK'), sg.Button('Cancel')]
]

async def event_in_game(event: str, values: dict):
    if event.startswith('OK'):
        switch_layout(4)
    elif event.startswith('Cancel'):
        switch_layout(3)

layout = [
    [
        sg.Column(layout_simple_choose_process, visible=True, key='simple_choose_process'),
        sg.Column(layout_complex_choose_process, visible=False, key='complex_choose_process'),
        sg.Column(layout_server_connect, visible=False, key='server_connect'),
        sg.Column(layout_choose_party, visible=False, key='choose_party'),
        sg.Column(layout_in_game, visible=False, key='in_game')   
    ]
]

list_events = [
    event_simple_choose_process,
    event_complex_choose_process,
    event_server_connect,
    event_choose_party,
    event_in_game
]

async def event_callback(event, values):
    await list_events[visible_layout](event, values)

window = sg.Window('Online', layout, size=(800, 600), finalize=True)

visible_layout = 0

def switch_layout(n: int):
    global visible_layout
    i = 0
    for element in layout[0]:
        if i == n:
            window[element.key].update(visible=True)
        else:
            window[element.key].update(visible=False)
        i += 1
    visible_layout = n

@sio.event
async def connect():
    print('connection established')

@sio.event
async def my_message(data):
    print('message received with ', data)
    await sio.emit('my response', {'response': 'my response'})

@sio.on("get party")
async def get_party(data):
    print(data)
    partys = data

@sio.event
async def disconnect():
    print('disconnected from server')

async def main():
    while True:
        event, values = window.read(timeout=100)
        if event == sg.WIN_CLOSED:
            break
        if event != '__TIMEOUT__':
            print(event, values)
        await event_callback(event, values)
    await sio.wait()

if __name__ == '__main__':
    asyncio.run(main())