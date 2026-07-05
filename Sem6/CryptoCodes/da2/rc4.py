# APOORVA KARNWAL 22BCE0756

def ksa(K):
    s = [i for i in range(256)]
    j = 0
    for i in range(256):
        T=K[i % len(K)]
        j = (j + s[i] + T) % 256
        s[i], s[j] = s[j], s[i]
        
    return s
    
def prga(s):
    i = 0
    j = 0
    while True:
        i = (i + 1) % 256
        j = (j + s[i]) % 256
        s[i], s[j] = s[j], s[i]
        t=(s[i] + s[j]) % 256
        yield s[t]        

def rc4_encrypt(plaintext, key):
    plaintext_bytes = [ord(char) for char in plaintext]
    key_bytes = [ord(char) for char in key]
    
    s_box = ksa(key_bytes)
    key_stream = prga(s_box)
    
    encrypted_text = ''
    for char in plaintext_bytes:
        encrypted_char = str(chr(char ^ next(key_stream)))
        encrypted_text += encrypted_char
        
    return encrypted_text

def rc4_decrypt(ciphertext, key):
    ciphertext_bytes = [ord(c) for c in ciphertext]
    key_bytes = [ord(char) for char in key]
    
    s_box = ksa(key_bytes)
    key_stream = prga(s_box)
    
    decrypted_text = ''
    for char in ciphertext_bytes:
        decrypted_char = str(chr(char ^ next(key_stream)))
        decrypted_text += decrypted_char
    
    return decrypted_text

plaintext = input('Enter your plaintext: ')
key = input('Enter your secret key: ')

ciphertext = rc4_encrypt(plaintext, key)
print('Encrypted Text: ')
print(ciphertext)

decrypted_text = rc4_decrypt(ciphertext, key)
print('Decrypted Text: ')
print(decrypted_text)
