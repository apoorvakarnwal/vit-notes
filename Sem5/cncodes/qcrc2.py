import socket

def crc(number,divisor):
    n = len(divisor)
    check = number[:n]

    for i in range(n,len(number)):
        if check[0] == '1':
            check = xor(check,divisor)
        check = check[1:] + number[i]
    
    if check[0] == '1':
        check = xor(check,divisor)
    
    return check[1:]

def xor(bits1,bits2):
    return ''.join(str(int(b1)^int(b2)) for b1,b2 in zip(bits1,bits2))

def main():
    client_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    host = 'localhost'
    port = 12345
    divisor = '1011'
    client_socket.connect((host,port))

    received_code = client_socket.recv(1024).decode('utf-8').strip()
    print(f"Received Code: {received_code}")
    crc_length = len(divisor) - 1
    data = received_code[:-crc_length]
    received_crc = received_code[-crc_length:]
    remainder = crc(data, divisor)
    if remainder == received_crc:
        print("CRC verification passed. No transmission errors detected.")
    else:
        print("CRC verification failed. Transmission errors detected.")
    text_data = ''.join(chr(int(data[i:i+8], 2)) for i in range(0, len(data), 8))
    print(f"Decoded Text: {text_data}")
    client_socket.close()

if __name__ == '__main__':
    main()