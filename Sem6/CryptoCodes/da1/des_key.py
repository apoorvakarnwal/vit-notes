pc2 = [   
    14, 17, 11, 24, 1, 5,
    3, 28, 15, 6, 21, 10,
    23, 19, 12, 4, 26, 8,
    16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
]

SHIFTS=[1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1]

def bytes_to_bits(data):
    return [int(b) for by in data for b in f"{by:08b}"]

def permute(data, box):
    return [data[p-1] for p in box]

def pc1(key_64):
    key_56=[]
    for i in range(1,len(key_64)+1):
        if(i%8!=0):
            key_56.append(key_64[i-1])
    return key_56

def key_generation(key_56):
    left, right=key_56[:28], key_56[28:]

    subkeys=[]
    for s in SHIFTS:
        left=left[s:]+left[:s]
        right=right[s:]+right[:s]
        combined=left+right
        sub=permute(combined, pc2)
        subkeys.append(sub)

    return subkeys

def bin_to_chr(bin_list):
    bin_str=''.join(map(str, bin_list))
    num=len(bin_list)//8
    res=''
    for i in range(num):
        x=bin_str[i*8: (i+1)*8]
        res+= chr(int(x,2))
    return res

def main():
    key=b'sdfghjkl'
    key_bits=bytes_to_bits(key)
    key_56=pc1(key_bits)
    subkeys=key_generation(key_56)

    for i in range(16):
        print(f"Round: {i+1}")
        print(bin_to_chr(subkeys[i]))

main()