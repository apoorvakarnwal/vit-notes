import socket
import time
HOST = 'localhost'
PORT = 65432
messages = ['Packet 0', 'Packet 1', 'Packet 2']
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
    client_socket.connect((HOST, PORT))
    client_socket.settimeout(3.0)
    for message in messages:
        while True:
            try:
                client_socket.sendall(message.encode())
                print(f"Sent: {message}")
                ack = client_socket.recv(1024).decode()
                if ack == 'ACK':
                    print(f"Received ACK for: {message}")
                    break
            except socket.timeout:
                print(f"Timeout! Resending: {message}")
        time.sleep(1)