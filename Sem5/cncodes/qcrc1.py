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
    return ''.join(str(int(b1) ^ int(b2)) for b1,b2 in zip(bits1,bits2))

def main():
    host = 'localhost'
    port = 12345
    divisor = '1011'
    server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    server_socket.bind((host,port))
    server_socket.listen(1)

    while True:
        client_socket,addr = server_socket.accept()
        print(f'Connection from addr : {addr}')

        data = input("Enter the data : ")
        binary_data = ''.join(format(ord(x),'08b') for x in data)
        print(binary_data)
        crc_code = crc(binary_data,divisor)
        final_code = binary_data+crc_code
        print(final_code)
        client_socket.send(final_code.encode('utf-8'))
        client_socket.close()

if __name__ == '__main__':
    main()