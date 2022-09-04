import eel
import socket

serverMACAddress = '98:D3:71:FE:18:91'
port = 1
s = socket.socket(socket.AF_BLUETOOTH, socket.SOCK_STREAM, socket.BTPROTO_RFCOMM)
s.connect((serverMACAddress,port))

eel.init('web')

@eel.expose
def forward_py():
    print('forward')
    s.send(bytes('f', 'utf-8'))

@eel.expose
def backward_py():
    print('backward')
    s.send(bytes('b', 'utf-8'))

@eel.expose
def left_py():
    print('left')
    s.send(bytes('l', 'utf-8'))

@eel.expose
def right_py():
    print('right')
    s.send(bytes('r', 'utf-8'))

@eel.expose
def stop_py():
    print('stop')
    s.send(bytes('s', 'utf-8'))

eel.start('index.html',  size=(1920, 1080))