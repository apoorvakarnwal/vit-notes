def caesar_encrypt(plaintext, shift):
    ciphertext = ""
    for char in plaintext:
        if char.isalpha():
            ascii_base = ord('A') if char.isupper() else ord('a')
            shifted = (ord(char) - ascii_base + shift) % 26
            ciphertext += chr(shifted + ascii_base)
        else:
            ciphertext += char
    return ciphertext

def caesar_decrypt(ciphertext, shift):
    return caesar_encrypt(ciphertext, -shift)


if __name__ == "__main__":
    message = input("Enter the message: ")
    shift = int(input("Enter the shift value: "))
    
    encrypted = caesar_encrypt(message, shift)
    print(f"Encrypted: {encrypted}")
    
    decrypted = caesar_decrypt(encrypted, shift)
    print(f"Decrypted: {decrypted}")
