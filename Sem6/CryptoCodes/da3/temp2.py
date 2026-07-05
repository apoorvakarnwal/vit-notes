import time 

SHA512_CONSTANTS = [
    0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
    0x3956c25bf348b538, 0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
    0xd807aa98a3030242, 0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
    0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 0xc19bf174cf692694,
    0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
    0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
    0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4,
    0xc6e00bf33da88fc2, 0xd5a79147930aa725, 0x06ca6351e003826f, 0x142929670a0e6e70,
    0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
    0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b,
    0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30,
    0xd192e819d6ef5218, 0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
    0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
    0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
    0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
    0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b,
    0xca273eceea26619c, 0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
    0x06f067aa72176fba, 0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
    0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
    0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817
]

INITIAL_HASH = [
    0x6a09e667f3bcc908, 0xbb67ae8584caa73b, 0x3c6ef372fe94f82b, 0xa54ff53a5f1d36f1,
    0x510e527fade682d1, 0x9b05688c2b3e6c1f, 0x1f83d9abfb41bd6b, 0x5be0cd19137e2179
]

def right_rotate(x, n):
    return (x >> n) | ((x << (64 - n)) & 0xFFFFFFFFFFFFFFFF)

def sha512(message):

    bit_len=len(message)*8
    padded=message

    padded+=b'\x80'

    while(len(padded)%128 !=112):
        padded+=b'\x00'
    
    padded+= bit_len.to_bytes(16, 'big')

    hash_values=INITIAL_HASH.copy()
    for i in range(0,len(padded),128):
        block=padded[i:i+128]
        w=[int.from_bytes(block[j:j+8],'big') for j in range(0,128, 8)]
        w+=[0]*64

        for t in range(16, 80):
            s0 = right_rotate(w[t-15], 1) ^ right_rotate(w[t-15], 8) ^ (w[t-15] >> 7)
            s1 = right_rotate(w[t-2], 19) ^ right_rotate(w[t-2], 61) ^ (w[t-2] >> 6)
            w[t] = (w[t-16] + s0 + w[t-7] + s1) & 0xFFFFFFFFFFFFFFFF
        
        a,b,c,d,e,f,g,h=hash_values
        for t in range(80):
            sigmae=right_rotate(e,14)^right_rotate(e,18)^right_rotate(e,41)
            sigmaa=right_rotate(a,28)^right_rotate(a,34)^right_rotate(a,39)
            maj=(a&b)^(c&b)^(a&c)
            ch=(e&f)^((~e)&g)
            temp1=(h+sigmae+ch+ w[t]+SHA512_CONSTANTS[t])& 0xFFFFFFFFFFFFFFFF
            temp2=(sigmaa+maj)& 0xFFFFFFFFFFFFFFFF

            h,g,f,e,d,c,b,a=g,f,e, (d+temp1)&0xFFFFFFFFFFFFFFFF,c,b,a, (temp1+temp2)&0xFFFFFFFFFFFFFFFF
        
        hash_values = [
            (hash_values[0] + a) & 0xFFFFFFFFFFFFFFFF,
            (hash_values[1] + b) & 0xFFFFFFFFFFFFFFFF,
            (hash_values[2] + c) & 0xFFFFFFFFFFFFFFFF,
            (hash_values[3] + d) & 0xFFFFFFFFFFFFFFFF,
            (hash_values[4] + e) & 0xFFFFFFFFFFFFFFFF,
            (hash_values[5] + f) & 0xFFFFFFFFFFFFFFFF,
            (hash_values[6] + g) & 0xFFFFFFFFFFFFFFFF,
            (hash_values[7] + h) & 0xFFFFFFFFFFFFFFFF
        ]
    digest = (
        hash_values[0].to_bytes(8, 'big') +
        hash_values[1].to_bytes(8, 'big') +
        hash_values[2].to_bytes(8, 'big') +
        hash_values[3].to_bytes(8, 'big') +
        hash_values[4].to_bytes(8, 'big') +
        hash_values[5].to_bytes(8, 'big') +
        hash_values[6].to_bytes(8, 'big') +
        hash_values[7].to_bytes(8, 'big')
    )

    return digest

            





def hmac_sha(key, message, hash_func=sha512, block_size=64, output_size=32):
    if len(key) > block_size:
        key = hash_func(key)
    if len(key) < block_size:
        key = key + b'\x00' * (block_size - len(key))
    
    ipad = bytes([k ^ 0x36 for k in key])
    opad = bytes([k ^ 0x5c for k in key])
    
    inner_hash = hash_func(ipad + message)
    
    outer_hash = hash_func(opad + inner_hash)
    
    return outer_hash[:output_size]

key = b'secret-key'
message_sizes = [1024, 10240, 102400]

# Testing HMAC for different message sizes
for size in message_sizes:
    message = b'\x00' * size
    
    # Measure time for SHA-128 (truncated SHA-256)
    start = time.time()
    mac_sha128 = hmac_sha(key, message, hash_func=sha512, output_size=16)  # Simulate SHA-128 (truncating SHA-512)
    time_sha128 = time.time() - start
    
    # Measure time for SHA-256
    start = time.time()
    mac_sha256 = hmac_sha(key, message, hash_func=sha512, output_size=32)  # SHA-256 (use full SHA-256)
    time_sha256 = time.time() - start
    
    # Measure time for SHA-512
    start = time.time()
    mac_sha512 = hmac_sha(key, message, hash_func=sha512, output_size=64)  # Full SHA-512
    time_sha512 = time.time() - start
    
    print(f"Message Size: {size} bytes")
    print(f"SHA-128 MAC: {mac_sha128.hex()}")
    print(f"Time SHA-128: {time_sha128:.6f}s")
    print(f"SHA-256 MAC: {mac_sha256.hex()}")
    print(f"Time SHA-256: {time_sha256:.6f}s")
    print(f"SHA-512 MAC: {mac_sha512.hex()}")
    print(f"Time SHA-512: {time_sha512:.6f}s")
    print("----------------------------------")
