sbox=[[0 for i in range(16)] for j in range(16)]

for i in range(16):
    for j in range(16):
        sbox[i][j]=(i*j)%256

def rot_word(w):
    return w[1:]+w[:1]

def sub_word(w):
    return bytes(sbox[b//16][b%16] for b in w)

def xor(w1,w2):
    return bytes(a^b for a,b in zip(w1,w2))

key=b'abcdefghijklmnoz'

w=[None]*44

for i in range(4):
    w[i]=key[i*4: (i+1)*4]

for i in range(4,44):
    temp=w[i-1]
    if(i%4==0):
        temp=sub_word(rot_word(temp))
    w[i]=xor(temp,w[i-4])

for i in range(44):
    print(f"w[{i}]: {w[i].decode('utf-8')}")