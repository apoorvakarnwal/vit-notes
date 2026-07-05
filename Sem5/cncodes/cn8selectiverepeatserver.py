import socket
import random

def receiver(total_frames, port=12345):
    received = [False] * total_frames
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
        s.bind(('localhost', port))
        print("Receiver ready...")
        while not all(received):
            data, addr = s.recvfrom(1024)
            frame_num = int(data.decode())
            if 0 <= frame_num < total_frames and not received[frame_num]:
                if random.random() < 0.2:
                    print(f"Frame {frame_num} lost.")
                else:
                    print(f"Received frame {frame_num}")
                    received[frame_num] = True
                    if random.random() >= 0.1:  # Simulate ACK loss
                        s.sendto(f"ACK {frame_num}".encode(), addr)
                        print(f"ACK {frame_num} sent")

if __name__ == "__main__":
    total_frames = int(input("Enter total number of frames: "))
    receiver(total_frames)
