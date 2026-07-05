E = [
    32,  1,  2,  3,  4,  5,  4,  5,  6,  7,  8,  9,
     8,  9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32,  1
]

P = [
    16,  7, 20, 21, 29, 12, 28, 17,  1, 15, 23, 26,
     5, 18, 31, 10,  2,  8, 24, 14, 32, 27,  3,  9,
    19, 13, 30,  6, 22, 11,  4, 25
]

PC1 = [
    57, 49, 41, 33, 25, 17,  9,  1, 58, 50, 42, 34, 26, 18,
    10,  2, 59, 51, 43, 35, 27, 19, 11,  3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,  7, 62, 54, 46, 38, 30, 22,
    14,  6, 61, 53, 45, 37, 29, 21, 13,  5, 28, 20, 12,  4
]

PC2 = [
    14, 17, 11, 24,  1,  5,  3, 28, 15,  6, 21, 10,
    23, 19, 12,  4, 26,  8, 16,  7, 27, 20, 13,  2,
    41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32
]

SHIFTS = [1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1]

S = [[(i * j) % 16 for j in range(16)] for i in range(4)]



def bin_to_text(bin):
    bin=''.join(map(str, bin))

    while (len(bin)%8!=0):
        bin+='0'
    num=len(bin)//8

    res=''
    for i in range(num):
        res+= chr(int(bin[i*8:(i+1)*8], 2 ))
    return res

def bytes_to_bits(text):
    return [int(bit) for by in text for bit in f"{by:08b}"]

def permute(data,box):
    return [data[p-1] for p in box]

def key_generation(key_56):
    left, right= key_56[:28], key_56[28:]
    subkeys=[]
    for s in SHIFTS:
        left=left[s:]+left[:s]
        right=right[s:]+right[:s]
        combined=left+right
        sub=permute(combined, PC2)
        subkeys.append(sub)

    return subkeys

def int_to_bits(s):
    return [int(b) for b in f"{s:04b}"]

def fiestal(right, subkey):
    temp=permute(right, E)
    temp=[a^b for a,b in zip(temp,subkey)]

    res=[]
    for i in range(8):
        chunk=temp[i*6:(i+1)*6]
        row=chunk[0]*2+chunk[5]
        col=chunk[1]<<3|chunk[2]<<2|chunk[3]<<1|chunk[4]
        s=S[row % 4][col % 16]
        res.extend(int_to_bits(s))
    temp=permute(res, P)
    return temp

def desencrypt(text,subkeys):
    left, right= text[:32], text[32:]

    for i in subkeys:
        oldl=left
        left=right
        f=(fiestal(right, i))
        right=[a^b for a,b in zip(f,oldl)]
    return right+left

def encrypt(text, key):
    text=bytes_to_bits(text)
    while(len(text)%64!=0):
        text.append(0)
    key=bytes_to_bits(key)
    key_56=permute(key,PC1)
    subkeys=key_generation(key_56)
    res=desencrypt(text,subkeys)

    return bin_to_text(res)

def main():
    text = b'zxcvbnm,'
    key = b'QWERTYUI'
    encrypted = encrypt(text, key)
    print("Encrypted:", encrypted)

main()