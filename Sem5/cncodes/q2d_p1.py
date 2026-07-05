import socket

# Function to calculate parity
def parity(data):
    row_parity = [sum(row) % 2 for row in data]
    rows = len(data)
    cols = len(data[0])
    col_parity = [sum(data[row][col] for row in range(rows)) % 2 for col in range(cols)]
    
    overall_parity = sum(row_parity) % 2 ^ sum(col_parity) % 2 
    
    # Append row parity to each row
    for i in range(rows):
        data[i].append(row_parity[i])
    
    # Append overall parity and column parity
    col_parity.append(overall_parity)
    data.append(col_parity)
    return data

# Convert the matrix to a string (binary)
def matrix_to_string(data):
    binary_data = ''
    for row in data:
        binary_data += ''.join(format(x, '08b') for x in row)
    return binary_data

def sender(data, host, port):
    data_with_parity = parity(data)
    
    # Convert the data to a binary string
    binary_data = matrix_to_string(data_with_parity)
    
    # Set up the server to listen for incoming client connections
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
        server_socket.bind((host, port))
        server_socket.listen(1)
        print(f"Server listening on {host}:{port}...")
        
        client_socket, addr = server_socket.accept()
        with client_socket:
            print(f"Connection established with {addr}")
            
            # Send the final data (matrix with parity) to the client
            client_socket.sendall(binary_data.encode())
            print("Data with parity sent to client.")

# Main function to start the server
def main():
    host = 'localhost'
    port = 12345
    data = [
        [1, 0, 0, 1, 1, 0, 0, 1],
        [1, 1, 1, 0, 0, 0, 1, 0],
        [0, 0, 1, 0, 0, 1, 0, 0],
        [1, 0, 0, 0, 0, 1, 0, 0]
    ]
    sender(data, host, port)

if __name__ == '__main__':
    main()
