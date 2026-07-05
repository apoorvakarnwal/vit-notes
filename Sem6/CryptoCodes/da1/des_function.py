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

def bytes_to_bits(data):
    return [int(b) for by in data for b in f"{by:08b}"]

def int_to_bits(n):
    return [int(b) for b in f"{n:04b}"]

def permute(data, box):
    return [data[p-1] for p in box ]

def binlist_to_chr(data):
    data=''.join(map(str,data))
    res=''
    num=len(data)//8
    for i in range(num):
        x=data[i*8:(i+1)*8]
        res+= chr(int(x,2))
    return res

def padded(data):
    while(len(data)%64!=0):
        data.append(0)
    return data

def fiestal(right,subkey):
    right=permute(right, E)
    right=[a^b for a,b in zip(right,subkey)]

    ans=[]
    for i in range(8):
        chunk=right[i*6:(i+1)*6]
        row=chunk[0]*2 + chunk[5]
        col= chunk[1]<<3 |chunk[2]<<2 |chunk[3]<<1 |chunk[4]
        s_val=S[row][col]
        s_val=int_to_bits(s_val)
        ans.extend(s_val)

    ans=permute(ans, P)

    return ans


def desEncrypt(text,subkeys):
    left, right=text[:32], text[32:]

    for subkey in subkeys:
        old_left=left
        left=right
        fnn=fiestal(right,subkey)
        right=[a^b for a,b in zip(old_left,fnn)]

    block=right+left
    return block



def encrypt(text, key):
    subkeys=[key,key,key,key,key,key,key,key]
    text=padded(text)
    ans=desEncrypt(text, subkeys)
    return binlist_to_chr(ans)


def main():
    text=b'zxcv'
    key=b'QWERTY'
    text=bytes_to_bits(text)
    key=bytes_to_bits(key)
    encrypted = encrypt(text, key)
    print("Encrypted (bytes):", encrypted)

main()