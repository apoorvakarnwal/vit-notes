import socket


def encode_data(msg):
    m=len(msg)
    r=0
    while(2**r>(m+r+1)):
        r+=1
    
    hamming_code=[0]*(m+r+1)
    k=0
    for i in range(1,len(hamming_code)):
        if(i&i-1 == 0):
            hamming_code[i]=0
        else:
            hamming_code[i] = int(msg[k])
            k+=1

    for i in range(r):
        x=2**i
        count=0
        for j in range(1,len(hamming_code)):
            if(x&j):
                count+=hamming_code[j]
        hamming_code[i]=count%2

    return hamming_code[1:]

def main():
    host='localhost'
    port = 1234

    msg="101"
    hamming_code=encode_data(msg)
    hamming_code_str=''.join(map(str,hamming_code))
    s_socket=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s_socket.bind((host,port))
    s_socket.listen()
    print(f"Server is listening...")

    while(True):
        conn,addr=s_socket.accept()
        print(f"Connected to {addr}")
        conn.send(hamming_code_str.encode('utf-8'))
        print(f'Sent Hamming code: {hamming_code_str}')
        conn.close()

if __name__ == '__main__':
    main()


