import socket
import random

def receive_frames(conn, window_size):
    buffer = ""
    while True:
        try:
            # Receive and buffer data
            data = conn.recv(1024).decode()
            if not data:
                break
            buffer += data
            frames = buffer.split('\n')

            # Process each frame
            for frame in frames[:-1]:
                if frame:
                    print(f"Received {frame.strip()}")
                    frame_num = int(frame.split()[1])

                    # Simulate packet loss (10% chance of packet loss)
                    if random.random() > 0.1:
                        ack_msg = f"ACK {frame_num}"
                        print(f"Sending acknowledgment for Frame {frame_num}")
                        conn.send(ack_msg.encode())
                    else:
                        print(f"Packet Loss for Frame {frame_num}")
                        nack_msg = f"NACK {frame_num}"
                        conn.send(nack_msg.encode())
            buffer = frames[-1]

        except Exception as e:
            print(f"Error: {e}")
            break

def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('localhost', 9999))
    server_socket.listen(1)
    print("Waiting for client connection...")
    conn, addr = server_socket.accept()
    print(f"Connected to {addr}")

    window_size = int(input("Enter the Window Size: "))
    receive_frames(conn, window_size)

    conn.close()
    server_socket.close()

if __name__ == "__main__":
    main()
