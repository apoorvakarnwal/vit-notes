IP = [
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17,  9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
]

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

FP = [
    40,  8, 48, 16, 56, 24, 64, 32,
    39,  7, 47, 15, 55, 23, 63, 31,
    38,  6, 46, 14, 54, 22, 62, 30,
    37,  5, 45, 13, 53, 21, 61, 29,
    36,  4, 44, 12, 52, 20, 60, 28,
    35,  3, 43, 11, 51, 19, 59, 27,
    34,  2, 42, 10, 50, 18, 58, 26,
    33,  1, 41,  9, 49, 17, 57, 25
]

S1 = [
    [14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7],
    [ 0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8],
    [ 4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0],
    [15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13]
]

S2 = [
    [15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10],
    [ 3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5],
    [ 0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15],
    [13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9]
]

S3 = [
    [10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8],
    [13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1],
    [13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7],
    [ 1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12]
]

S4 = [
    [ 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15],
    [13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9],
    [10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4],
    [ 3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14]
]

S5 = [
    [ 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9],
    [14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6],
    [ 4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14],
    [11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3]
]

S6 = [
    [12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11],
    [10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8],
    [ 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10, 11, 13,  6,  1],
    [ 0, 13,  1,  5, 10,  7, 11,  6, 15, 14,  9,  3, 12,  4,  2,  8]
]

S7 = [
    [ 6,  2,  1, 13,  4, 11,  8,  9,  7, 10, 14, 12,  5, 15,  0,  3],
    [15,  8,  4, 13, 12,  3,  1, 11, 10,  2,  9,  7,  5,  0, 14,  6],
    [11,  1, 12,  9, 10,  8, 15,  4,  2, 14,  0,  5, 13,  7,  3,  6],
    [10, 15,  4,  2,  1, 12,  5, 14,  9, 11, 13,  6,  7,  3,  0,  8]
]

S8 = [
    [ 4, 15,  1, 14, 12,  8,  9,  6, 13, 10,  7,  5,  3, 11,  0,  2],
    [12,  7,  6, 10, 15,  9,  5, 14, 11,  8,  4,  3,  0,  1,  2, 13],
    [11, 10,  7,  5, 13,  6,  0,  2, 15, 14, 12,  3,  1,  9,  4,  8],
    [13,  8,  5,  0, 11, 14,  6, 15,  9, 12,  2,  7,  3,  1, 10,  4]
]

PC1 = [
    57, 49, 41, 33, 25, 17,  9,
     1, 58, 50, 42, 34, 26, 18,
    10,  2, 59, 51, 43, 35, 27,
    19, 11,  3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
     7, 62, 54, 46, 38, 30, 22,
    14,  6, 61, 53, 45, 37, 29,
    21, 13,  5, 28, 20, 12,  4
]

PC2 = [
    14, 17, 11, 24,  1,  5,
     3, 28, 15,  6, 21, 10,
    23, 19, 12,  4, 26,  8,
    16,  7, 27, 20, 13,  2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
]

SHIFTS = [1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1]

import numpy as np

def permute(block, permutation):
    return [block[p-1] for p in permutation]

def bit_to_int(bits):
    return int(''.join(map(str, bits)), 2)

def int_to_bit(n, length=4):
    return [int(b) for b in f'{n:0{length}b}']

def bytes_to_bits(data):
    return [int(b) for byte in data for b in f'{byte:08b}']

def bits_to_bytes(bits):
    while len(bits) % 8 != 0:
        bits.append(0)
    return bytes(int(''.join(map(str, bits[i:i+8])), 2) for i in range(0, len(bits), 8))

def generate_subkeys(key):
    if len(key) != 8:
        raise ValueError("Key must be 8 bytes long")
    
    key_bits = bytes_to_bits(key)
    key_pc1 = permute(key_bits, PC1)
    left, right = key_pc1[:28], key_pc1[28:]
    subkeys = []
    for shift in SHIFTS:
        left = left[shift:] + left[:shift]
        right = right[shift:] + right[:shift]
        combined = left + right
        subkey = permute(combined, PC2)
        subkeys.append(subkey)
    return subkeys

def feistel_function(right, subkey):
    expanded = permute(right, E)
    xored = [a ^ b for a, b in zip(expanded, subkey)]
    sbox_output = []
    s_boxes = [S1, S2, S3, S4, S5, S6, S7, S8]
    for i in range(8):
        chunk = xored[i*6:(i+1)*6]
        row = chunk[0] * 2 + chunk[5]
        col = bit_to_int(chunk[1:5])
        sbox_val = s_boxes[i][row][col]
        sbox_output.extend(int_to_bit(sbox_val))
    return permute(sbox_output, P)

def des_block_encrypt(block, subkeys):
    block = permute(block, IP)
    left, right = block[:32], block[32:]
    for subkey in subkeys:
        old_left = left
        left = right
        f_output = feistel_function(right, subkey)
        right = [a ^ b for a, b in zip(old_left, f_output)]
    final_block = right + left
    return permute(final_block, FP)

def des_block_decrypt(block, subkeys):
    block = permute(block, IP)
    left, right = block[:32], block[32:]
    for subkey in reversed(subkeys):
        old_left = left
        left = right
        f_output = feistel_function(right, subkey)
        right = [a ^ b for a, b in zip(old_left, f_output)]
    final_block = right + left
    return permute(final_block, FP)

def pad(data):
    padding_length = 8 - (len(data) % 8)
    padding = bytes([padding_length] * padding_length)
    return data + padding

def unpad(data):
    padding_length = data[-1]
    return data[:-padding_length]

def encrypt(plaintext, key):
    if isinstance(plaintext, str):
        plaintext = plaintext.encode('utf-8')
    
    subkeys = generate_subkeys(key)
    plaintext = pad(plaintext)
    bits = bytes_to_bits(plaintext)
    encrypted_bits = []
    for i in range(0, len(bits), 64):
        block = bits[i:i+64]
        encrypted_block = des_block_encrypt(block, subkeys)
        encrypted_bits.extend(encrypted_block)
    return bits_to_bytes(encrypted_bits)

def decrypt(ciphertext, key):
    subkeys = generate_subkeys(key)
    bits = bytes_to_bits(ciphertext)
    decrypted_bits = []
    for i in range(0, len(bits), 64):
        block = bits[i:i+64]
        decrypted_block = des_block_decrypt(block, subkeys)
        decrypted_bits.extend(decrypted_block)
    return unpad(bits_to_bytes(decrypted_bits))

def main():
    key = b'SecretKy'
    message = input("Enter the message: ")
    encrypted = encrypt(message, key)
    print("Encrypted (bytes):", encrypted)
    print("Encrypted (hex):", encrypted.hex())
    decrypted = decrypt(encrypted, key)
    print("Decrypted:", decrypted.decode('utf-8'))

if __name__ == "__main__":
    main()