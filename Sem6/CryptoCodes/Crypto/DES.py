import base64
import secrets
from Crypto.Cipher import DES
from Crypto.Util.Padding import pad, unpad

def generate_key():
    return base64.b64encode(secrets.token_bytes(8)).decode()

def encrypt(plaintext, key):
    key_bytes = base64.b64decode(key)
    cipher = DES.new(key_bytes, DES.MODE_ECB)
    encrypted_bytes = cipher.encrypt(pad(plaintext.encode(), DES.block_size))
    return base64.b64encode(encrypted_bytes).decode()

def decrypt(encrypted_text, key):
    key_bytes = base64.b64decode(key)
    cipher = DES.new(key_bytes, DES.MODE_ECB)
    decrypted_bytes = unpad(cipher.decrypt(base64.b64decode(encrypted_text)), DES.block_size)
    return decrypted_bytes.decode()

def main():
    plaintext = input("Enter the plaintext: ")
    key = generate_key()
    print("Generated Key:", key)
    
    encrypted_text = encrypt(plaintext, key)
    print("Encrypted text:", encrypted_text)
    
    decrypted_text = decrypt(encrypted_text, key)
    print("Decrypted text:", decrypted_text)

if __name__ == "__main__":
    main()
