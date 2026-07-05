

def right(n,s):
    return ((n<<s)|(n>>(32-n)))& 0xFFFFFFFF

def sha(data):
    bit_len=len(data)*8

    data+=b'\x80'
    while(len(data)%64!=56):
        data+=b'\x00'
    data+= bit_len.to_bytes(8, 'little')
    
    a0 = 0x67452301
    b0 = 0xEFCDAB89
    c0 = 0x98BADCFE
    d0 = 0x10325476
    for i in range(0,len(data),64):
        block=data[i:i+64]
        M=[int.from_bytes(block[j:j+4], 'little') for j in range(0,64,4)]

        A = a0
        B = b0
        C = c0
        D = d0
        for k in range(64):
            if k < 16:
                f = F(B, C, D)
                g = k
            elif k < 32:
                f = G(B, C, D)
                g = (5 * k + 1) % 16
            elif k < 48:
                f = H(B, C, D)
                g = (3 * k + 5) % 16
            else:
                f = I(B, C, D)
                g = (7 * k) % 16
            
            temp = (A + f + T[k] + M[g]) & 0xFFFFFFFF
            temp = left_rotate(temp, s[k])
            temp = (B + temp) & 0xFFFFFFFF

            A, B, C, D = D, temp, B, C
        a0=a0+A
    return (
        hashval[i].to_bytes(8, 'little')
    )



def hmac_sha(key, message):
    size=1024//8
    if(len(key)>size):
        key=sha(key)
    if(len(key)<size):
        key+=b'\x00'*(size-len(key))
    
    ipad=bytes([a^0x36 for a in key])
    opad=bytes([a^0x5C for a in key])

    inn=sha(ipad+message)
    inn=sha(opad+inn)
    return inn.hex()




key = b'secret-key'
message = b'Its a good day'
print(sha(message))
mac = hmac_sha(key, message)
print(mac)