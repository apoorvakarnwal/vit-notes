import socket 
import time 
HOST = 'localhost' 
PORT = 1236
i = 0 

def lcrvcr(mesg):
    lcr=[]
    vcr=[]
    idx=0
    for m in mesg:
        for i in m:
            lcr[idx]+=int(i)
        idx+=1
    
    for i in lcr:
        i=i%2

    for i in range(len(mesg)):
        for m in mesg:
            vcr[i]=int(m[i])
    for i in vcr:
        i=i%2

    lastbitint=0
    for i in vcr:
        lastbitint+=i
    lastbitint=lastbitint%2
    last=''
    for i in lcr:
        last+=str(i)
    last+=str(lastbitint)
        
        
    msg=[]
    idx23=0
    for m in mesg:
        x=m+str(lcr[idx23])
        msg.append(x)
    msg.append(last)

    return lcr,vcr

recieved_msg=[]
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
    server_socket.bind((HOST, PORT))
    server_socket.listen()
    print(f"Server listening on {HOST}:{PORT}")
    conn, addr = server_socket.accept()
    with conn:
        print(f"Connected by {addr}") 
        while True:
            data = conn.recv(1024) 
            if not data: 
                break 
            message = data.decode()
            recieved_msg.append(message)

            print(f"Received: {message}")
            i = i + 1 
            if i == 4 :
                time.sleep(5)
                print("sleep")
            conn.sendall(b'ACK')
            print(f"ACK sent to client for {message}")

        
        lcr,vcr=lcrvcr(recieved_msg)
        error=0
        for i in lcr:
            if i !=0:
                error=1
        for i in vcr:
            if i !=0:
                error=1

        if(error==1):
            print(f"error is present")
        else:
            print("no error")
