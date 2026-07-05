# Create S-Box
def create_sbox():
    sbox = [[0 for _ in range(16)] for _ in range(16)]
    for i in range(16):
        for j in range(16):
            sbox[i][j] = (i * j) % 256
    return sbox

sbox = create_sbox()

def rot_word(word):
    return word[1:] + word[:1]

def sub_word(word):
    return bytes(sbox[b // 16][b % 16] for b in word)

def xor_words(word1, word2):
    return bytes(b1 ^ b2 for b1, b2 in zip(word1, word2))


key_bytes = b'abcdefghijklmnoz'

w = [None] * 44

for i in range(4):
    w[i] = key_bytes[4*i: 4*(i+1)]

for i in range(4, 44):
    temp = w[i - 1]

    if i % 4 == 0:
        temp = sub_word(rot_word(temp))

    w[i] = xor_words(w[i - 4], temp)
    print(f"w[{i}] = {w[i]}")