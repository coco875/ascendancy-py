from aiohttp import web
import socketio
import session

# create a Socket.IO server
sio = socketio.AsyncServer(async_mode='aiohttp')

# wrap with ASGI application
app = web.Application()
sio.attach(app)

room:list[session.Session] = []

@sio.event
async def connect(sid, environ):
    print('connect ', sid)

@sio.on("get party")
async def get_party(sid, data):
    print("get party")
    await sio.emit("get party", room=[[i, room[i].current_day, len(room[i].players)] for i in range(len(room))])

@sio.on("create party")
async def create_party(sid, data):
    print("create party")
    room.append(session.Session(sid))

@sio.on("join party")
async def join_party(sid, data):
    print("join party")
    room[data].add_player(sid)

@sio.event
async def my_message(sid, data):
    print('message ', data)

@sio.event
async def disconnect(sid):
    print('disconnect ', sid)

if __name__ == '__main__':
    web.run_app(app)