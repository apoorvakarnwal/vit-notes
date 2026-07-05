import socket

def calculate_checksum(binary_data, num_bits=16):
    #text_data = ''.join(chr(int(data[i:i+8], 2)) for i in range(0, len(data), 8))

    total = sum(int(binary_data[i:i+8], 2) for i in range(0, len(binary_data), 8))
    return total & ((1 << num_bits) - 1)

def sender(data, host, port):
    binary_data = ''.join(format(ord(x), '08b') for x in data)
    print(f"\n****SENDER SIDE****")
    print(f"DATA IN BINARY (SENT): {binary_data}")
    
    checksum = calculate_checksum(binary_data, 16)
    checksum_binary = format(checksum, '016b')
    
    print(f"CHECKSUM (SENT): {checksum_binary}")
    
    # Send data and checksum over the network
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
        server_socket.bind((host, port))
        server_socket.listen(1)
        print(f"Waiting for connection on {host}:{port}...")
        
        client_socket, addr = server_socket.accept()
        with client_socket:
            print(f"Connection established with {addr}")
            
            # Combine data and checksum to send to the receiver
            final_code = binary_data + checksum_binary
            client_socket.sendall(final_code.encode())
            print("Data sent to the receiver.")

def main():
    host = 'localhost'
    port = 1238
    data = input("Enter the data: ")
    sender(data, host, port)

if __name__ == '__main__':
    main()
