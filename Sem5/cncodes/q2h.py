import socket

def decode_hamming(encoded_message):
    n = len(encoded_message)
    r = 0
    while 2**r < n + 1:
        r += 1
        
    error_pos = 0
    for i in range(r):
        x = 2**i
        count = 0
        for j in range(1, n + 1):
            if j & x:
                count += int(encoded_message[j - 1])
        if count % 2 != 0:
            error_pos += x

    if error_pos == 0:
        print('No error detected in Hamming code.')
    else:
        print(f'Error detected at position: {error_pos}')

    corrected_message = list(encoded_message)
    if error_pos > 0:
        corrected_message[error_pos - 1] = '0' if encoded_message[error_pos - 1] == '1' else '1'
        print('Error corrected in Hamming code.')

    corrected_message = ''.join(corrected_message)
    original_data = []
    for i in range(1, len(corrected_message) + 1):
        if i & (i - 1) != 0:
            original_data.append(corrected_message[i - 1])

    return ''.join(original_data)

def main():
    host = '127.0.0.1'
    port = 12345
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        client_socket.connect((host, port))
        hamming_code = client_socket.recv(1024).decode('utf-8').strip()
        print(f'Received Hamming code: {hamming_code}')
        
        decoded_data = decode_hamming(hamming_code)
        print(f'Decoded data (binary): {decoded_data}')
    except Exception as e:
        print(f"Error: {e}")
    finally:
        client_socket.close()

if __name__ == '__main__':
    main()
