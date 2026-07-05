import socket

def transmission(client_socket, window_size, total_frames):
    frame_number = 1
    total_transmissions = 0

    while frame_number <= total_frames:
        try:
            # Send frames in current window
            for frame in range(frame_number, min(frame_number + window_size, total_frames + 1)):
                message = f"Frame {frame}\n"
                client_socket.send(message.encode())
                print(f"Sending {message.strip()}")
                total_transmissions += 1

            # Receive acknowledgments for each frame in the window
            ack_count = 0
            for frame in range(frame_number, min(frame_number + window_size, total_frames + 1)):
                ack = client_socket.recv(1024).decode()
                if ack == f"ACK {frame}":
                    print(f"Acknowledgment received for Frame {frame}")
                    ack_count += 1
                else:
                    print(f"Timeout! Frame {frame} not received. Retransmitting window...")
                    break

            # Move to next set of frames if all frames in window were acknowledged
            frame_number += ack_count

        except (BrokenPipeError, ConnectionResetError):
            print(f"Connection lost while sending frame {frame_number}. Ending transmission.")
            break

    return total_transmissions

def main():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('localhost', 9999))
    try:
        total_frames = int(input("Enter the Total number of frames: "))
        window_size = int(input("Enter the Window Size: "))
        total_transmissions = transmission(client_socket, window_size, total_frames)
        print(f"Total number of frames sent and resent: {total_transmissions}")
    finally:
        client_socket.close()

if __name__ == "__main__":
    main() 