E = [
    32,  1,  2,  3,  4,  5,
     4,  5,  6,  7,  8,  9,
     8,  9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32,  1
]
S = [[(i * j) % 16 for j in range(16)] for i in range(4)]
P = [
    16,  7, 20, 21,
    29, 12, 28, 17,
     1, 15, 23, 26,
     5, 18, 31, 10,
     2,  8, 24, 14,
    32, 27,  3,  9,
    19, 13, 30,  6,
    22, 11,  4, 25
]

SHIFTS = [1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1]

def permute(block, mat):
    return [block[p-1] for p in mat]

def int_to_bits(n):
    return [int(b) for b in f'{n:04b}']

def bits_to_int(bits):
    return int(''.join(map(str,bits)),2)

def bits_to_bytes(bits):
    while len(bits)%8 !=0:
        bits.append(0)
    return bytes(int(''.join(map(str, bits[i:i+8])), 2) for i in range(0,len(bits),8))

def bytes_to_bits(data):
    return [int(b) for by in data for b in f'{by:08b}']


def pad(data):
    p=8-(len(data)%8)
    pdd=bytes([p]*p)
    return data+pdd

def key_generation(key):
    x=bytes_to_bits(key)
    subkeys = [x,x,x,x,x,x,x,x]
    return subkeys


def fn(right, subkey):
    r=permute(right,E)
    xor=[a^b for a,b in zip(r,subkey)]
    ans=[]
    for i in range(8):
        chunk=xor[i*6:(i+1)*6]
        row=chunk[0]*2+chunk[5]
        col=bits_to_int(chunk[1:5])
        s=S[row][col]
        s=int_to_bits(s)
        ans.extend(s)
    return permute(ans,P)


def desencrypt(block,subkeys):
    left,right=block[:32], block[32:]
    for s in subkeys:
        old_left=left
        left=right
        f=fn(right,s)
        right=[a^b for a,b in zip(f,old_left)]
    block=right+left
    return block



def encrypt(data,key):
    data=data.encode('utf-8')
    data=pad(data)
    bits=bytes_to_bits(data)
    otp=[]
    subkeys=key_generation(key)
    for i in range(0,len(bits),64):
        block=bits[i:i+64]
        ans=desencrypt(block,subkeys)
        otp.extend(ans)

    return bits_to_bytes(otp)

def decrypt():
    pass

def main():
    key = b'QWERTY'
    message = "zxcv"
    encrypted = encrypt(message, key)
    print("Encrypted (bytes):", encrypted)
    
    print("Encrypted (hex):", encrypted.hex())

if __name__ == "__main__":
    main()