import socket

# Function to check parity for rows, columns, and overall
def check_parity(data):
    rows = len(data)
    cols = len(data[0]) - 1  # Subtract 1 for row parity column
    
    row_parity = [sum(row[:-1]) % 2 for row in data]
    
    col_parity = [sum(data[row][col] for row in range(rows)) % 2 for col in range(cols)]
    
    overall_parity = data[rows-1][cols]
    
    row_check = all(row_parity[i] == data[i][cols] for i in range(rows))
    col_check = all(col_parity[i] == data[rows-1][i] for i in range(cols))
    
    overall_check = (sum(row_parity) % 2 ^ sum(col_parity) % 2) == overall_parity
    
    return row_check, col_check, overall_check

def string_to_matrix(binary_data, rows, cols):
    matrix = []
    index = 0
    for i in range(rows):
        matrix.append([int(binary_data[index + j:index + j + 8], 2) for j in range(0, cols * 8, 8)])
        index += cols * 8
    return matrix

def receiver(host, port):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
        client_socket.connect((host, port))
        received_code = client_socket.recv(1024).decode()
        rows = 4
        cols = 8
        matrix = string_to_matrix(received_code, rows, cols + 1)  # +1 for row parity column
        
        print(f"\n****RECEIVER SIDE****")
        print(f"RECEIVED MATRIX WITH PARITY:")
        for row in matrix:
            print(row)
        
        # Check if the received matrix parities are correct
        row_check, col_check, overall_check = check_parity(matrix)
        
        if row_check and col_check and overall_check:
            print("Parity check passed! No transmission errors detected.")
        else:
            print("Parity check failed! Transmission errors detected.")

def main():
    host = 'localhost'
    port = 12345
    receiver(host, port)

if __name__ == '__main__':
    main()
