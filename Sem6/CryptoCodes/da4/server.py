import ssl
import socket
CERT_FILE = 'server.crt'
KEY_FILE = 'server.key'

bindsocket = socket.socket()
bindsocket.bind(('0.0.0.0', 8443))
bindsocket.listen(5)

context = ssl.create_default_context(ssl.Purpose.CLIENT_AUTH)
context.load_cert_chain(certfile=CERT_FILE, keyfile=KEY_FILE)

print("Server is listening on port 8443...")

while True:
    newsocket, fromaddr = bindsocket.accept()
    with context.wrap_socket(newsocket, server_side=True) as ssock:
        print("Connection from:", fromaddr)
        data = ssock.recv(1024)
        print("Received:", data.decode())
        ssock.send(b'Hello from secure server!')

