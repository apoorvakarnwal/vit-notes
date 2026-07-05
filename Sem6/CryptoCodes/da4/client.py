import socket
import ssl

HOST = 'localhost'
PORT = 8443

context = ssl.create_default_context()
context.check_hostname = False
context.verify_mode = ssl.CERT_NONE

with socket.create_connection((HOST, PORT)) as sock:
    with context.wrap_socket(sock, server_hostname=HOST) as ssock:
        print("SSL connection established.")
        ssock.send(b"Hello secure server!")
        data = ssock.recv(1024)
        print("Received:", data.decode())

