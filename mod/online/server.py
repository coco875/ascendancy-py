from aiohttp import web
import socketio
import sys

if __name__ == '__main__':
    current_dir = sys.path[0]
    back_to_root = "\\".join(i for i in current_dir.split('\\')[:-2])
    print(back_to_root)
    sys.path.append(back_to_root+"\\tools")
    sys.path.append(back_to_root)
import sessions
from tools import ascendancy_lib

# create a Socket.IO server
sio = socketio.AsyncServer(async_mode='aiohttp')

# wrap with ASGI application
app = web.Application()
sio.attach(app)

room:list[sessions.Session] = []

def get_session(sid):
    for i in range(len(room)):
        if sid in room[i].players:
            return room[i]

@sio.event
async def connect(sid, environ):
    print('connect ', sid)

@sio.on("get party")
async def get_party(sid):
    print("get party")
    await sio.emit("get party", data=[[i, room[i].current_day, len(room[i].players)] for i in range(len(room))])

@sio.on("create party")
async def create_party(sid):
    print("create party")
    room.append(sessions.Session(sid))

@sio.on("join party")
async def join_party(sid, data):
    print("join party")
    room[data].add_player(sid)

@sio.on("get all race")
async def get_all_race(sid):
    session = get_session(sid)
    await sio.emit("get all race", data=session.get_all_race(sid))

@sio.on("set race")
async def set_race(sid, data):
    session = get_session(sid)
    race = ascendancy_lib.bytes_to_Struct(data[0], ascendancy_lib.asc.Model.Enum.Race)
    session.set_race(sid, race, data[1])

@sio.event
async def my_message(sid, data):
    print('message ', data)

@sio.event
async def disconnect(sid):
    print('disconnect ', sid)

if __name__ == '__main__':
    web.run_app(app, host="localhost", port=5000)