from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from base64 import b64encode, b64decode

def pad(text):
    # Padding to make sure the text length is a multiple of 16
    return text + (16 - len(text) % 16) * chr(16 - len(text) % 16)

def unpad(text):
    return text[:-ord(text[-1])]

def encrypt(plain_text, key):
    cipher = AES.new(key, AES.MODE_ECB)
    encrypted_bytes = cipher.encrypt(pad(plain_text).encode())
    return b64encode(encrypted_bytes).decode()

def decrypt(encrypted_text, key):
    cipher = AES.new(key, AES.MODE_ECB)
    decrypted_bytes = cipher.decrypt(b64decode(encrypted_text))
    return unpad(decrypted_bytes.decode())

def generate_key():
    return get_random_bytes(16)  # AES-128 requires a 16-byte key

def print_round_keys(key):
    print("Round Keys")
    for round_num in range(11):
        print(f"RoundKey{round_num}:")
        for i in range(len(key)):
            print(f"{key[i]:02X}", end=' ')
            if (i + 1) % 4 == 0:
                print()
    print()

if __name__ == "__main__":
    message = input("Enter the plaintext: ")
    secret_key = generate_key()
    print_round_keys(secret_key)
    encrypted_text = encrypt(message, secret_key)
    print("Encrypted Text:", encrypted_text)
    decrypted_text = decrypt(encrypted_text, secret_key)
    print("Decrypted Text:", decrypted_text)