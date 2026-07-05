import socket

def encode_hamming(data):
    m = len(data)
    r = 0
    while 2**r < m + r + 1:
        r += 1

    hamming_code = [0] * (m + r + 1)
    k = 0
    for i in range(1, len(hamming_code)):
        if i & (i - 1) == 0:
            hamming_code[i] = 0
        else:
            hamming_code[i] = int(data[k])
            k += 1

    for i in range(r):
        x = 2**i
        count = 0
        for j in range(1, len(hamming_code)):
            if j & x:
                count += hamming_code[j]
        hamming_code[x] = count % 2

    return hamming_code[1:]

def main():
    host = '127.0.0.1'
    port = 12345
    data_bits = "101"
    
    hamming_code = encode_hamming(data_bits)
    hamming_code_str = ''.join(map(str, hamming_code))
    
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))
    server_socket.listen()
    print("Server is listening...")

    while True:
        client_socket, addr = server_socket.accept()
        print(f'Connection from: {addr}')
        
        client_socket.send(hamming_code_str.encode('utf-8'))
        print(f'Sent Hamming code: {hamming_code_str}')
        
        client_socket.close()

if __name__ == '__main__':
    main()
