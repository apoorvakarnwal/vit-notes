from Crypto.Cipher import AES
from Crypto.Util.Padding import pad

def print_state(title, state):
    print(title)
    for row in state:
        print(row)

def aes_encrypt(plaintext, key):
    cipher = AES.new(bytes(key), AES.MODE_ECB)
    ciphertext = cipher.encrypt(bytes(plaintext))
    return list(ciphertext)

# Given plaintext and key
plaintext = [
    0x00, 0x01, 0x02, 0x03,
    0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B,
    0x0C, 0x0D, 0x0E, 0x0F
]

key = [
    0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01
]

# Perform AES encryption
ciphertext = aes_encrypt(plaintext, key)

# Print step-by-step results
print("\nInitial Plaintext:")
print_state("State:", [plaintext[i:i+4] for i in range(0, 16, 4)])

print("\nEncryption Steps:")
print_state("Ciphertext:", [ciphertext[i:i+4] for i in range(0, 16, 4)])
