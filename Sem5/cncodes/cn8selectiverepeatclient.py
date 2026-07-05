import socket

def sender(total_frames, window_size, timeout=2, port=12345):
    acknowledged = [False] * total_frames
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
        s.settimeout(timeout)
        receiver_addr = ('localhost', port)
        print("Sender started...")
        base = 0
        while base < total_frames:
            for i in range(base, min(base + window_size, total_frames)):
                if not acknowledged[i]:
                    s.sendto(str(i).encode(), receiver_addr)
                    print(f"Sent frame {i}")
            try:
                ack, _ = s.recvfrom(1024)
                ack_num = int(ack.decode().split()[1])
                if 0 <= ack_num < total_frames:
                    acknowledged[ack_num] = True
                    print(f"ACK {ack_num} received")
                    while base < total_frames and acknowledged[base]:
                        base += 1  # Slide window
            except socket.timeout:
                print("Timeout, resending unacknowledged frames...")

if __name__ == "__main__":
    total_frames = int(input("Enter total number of frames: "))
    window_size = int(input("Enter window size: "))
    sender(total_frames, window_size)
