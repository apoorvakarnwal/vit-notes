import socket

# Function to calculate checksum
def calculate_checksum(binary_data, num_bits=16):
    total = sum(int(binary_data[i:i+8], 2) for i in range(0, len(binary_data), 8))
    return total & ((2** num_bits) - 1)

def receiver(host, port):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
        client_socket.connect((host, port))
        received_code = client_socket.recv(1024).decode()
        
        data = received_code[:-16]
        received_checksum = received_code[-16:]
        
        # Calculate the checksum for the received data
        calculated_checksum = calculate_checksum(data, 16)
        calculated_checksum_binary = format(calculated_checksum, '016b')
        
        print(f"\n****RECEIVER SIDE****")
        print(f"RECEIVED DATA (BINARY): {data}")
        print(f"RECEIVED CHECKSUM: {received_checksum}")
        print(f"CALCULATED CHECKSUM: {calculated_checksum_binary}")
        
        # Verify checksum
        if calculated_checksum_binary == received_checksum:
            print("Checksum verification passed. No transmission errors detected.")
        else:
            print("Checksum verification failed. Transmission errors detected.")
        
        # Decode the binary data into text
        text_data = ''.join(chr(int(data[i:i+8], 2)) for i in range(0, len(data), 8))
        print(f"DECODED TEXT: {text_data}")

def main():
    host = 'localhost'
    port = 1238
    receiver(host, port)

if __name__ == '__main__':
    main()
