import socket 
import time 
HOST = 'localhost' 
PORT = 1234
i = 0 
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
    server_socket.bind((HOST, PORT))
    server_socket.listen()
    print(f"Server listening on {HOST}:{PORT}")
    conn, addr = server_socket.accept()
    with conn:
        print(f"Connected by {addr}") 
        while True:
            data = conn.recv(1024) 
            if not data:
                break 
            message = data.decode()
            print(f"Received: {message}")
            i = i + 1 
            if i == 2 :
                time.sleep(5)
                print("sleep")
            conn.sendall(b'ACK')
            print(f"ACK sent to client for {message}")