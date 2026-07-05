# APOORVA KARNWAL 22BCE0756

def left_rotate(x, n):
    return ((x << n) | (x >> (32 - n))) & 0xFFFFFFFF
def F(x, y, z):
    return (x & y) | ((~x) & z)
def G(x, y, z):
    return (x & z) | ((~z) & y)
def H(x, y, z):
    return x ^ y ^ z
def I(x, y, z):
    return y ^ (x | (~z) & 0xFFFFFFFF)

T = [
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
]

s = [
    7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
    5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
    4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
    6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
]

def md5(message):
    a0 = 0x67452301
    b0 = 0xEFCDAB89
    c0 = 0x98BADCFE
    d0 = 0x10325476

    original_length = len(message)

    bit_length = original_length * 8

    padded = message

    padded+=b'\x80'
    
    while (len(padded) % 64) != 56:
        padded+=b'\x00'
    padded += bit_length.to_bytes(8, byteorder='little')
    
    for i in range(0, len(padded), 64):
        block = padded[i:i+64]
        M = [int.from_bytes(block[j:j+4], 'little') for j in range(0, 64, 4)]

        A = a0
        B = b0
        C = c0
        D = d0

        for k in range(80):
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

        a0 = (a0 + A) & 0xFFFFFFFF
        b0 = (b0 + B) & 0xFFFFFFFF
        c0 = (c0 + C) & 0xFFFFFFFF
        d0 = (d0 + D) & 0xFFFFFFFF

    digest = (
        a0.to_bytes(4, 'little') +
        b0.to_bytes(4, 'little') +
        c0.to_bytes(4, 'little') +
        d0.to_bytes(4, 'little')
    )
    return digest

def hmac_md5(key, message):
    block_size = 64
    if len(key) > block_size:
        key = md5(key)
    if len(key) < block_size:
        key = key + b'\x00' * (block_size - len(key))

    ipad = bytes([k ^ 0x36 for k in key])
    opad = bytes([k ^ 0x5c for k in key])

    inner_hash = md5(ipad + message)
    hmac = md5(opad + inner_hash)

    return hmac.hex()

key = b'secret-key'
message = b'Its a good day'
print(md5(message))
mac = hmac_md5(key, message)
print(mac)