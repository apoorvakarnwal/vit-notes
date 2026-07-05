def rc4(key, plaintext):
    S = list(range(256))
    j = 0
    for i in range(256):
        j = (j + S[i] + key[i % len(key)]) % 256
        S[i], S[j] = S[j], S[i]

    i = j = 0
    ciphertext = []
    for char in plaintext:
        i = (i + 1) % 256
        j = (j + S[i]) % 256
        S[i], S[j] = S[j], S[i]
        k = S[(S[i] + S[j]) % 256]
        ciphertext.append(char ^ k)

    return bytes(ciphertext)

key = b'SecretKey'
plaintext = b'Hello, World!'
ciphertext = rc4(key, plaintext)
print("Ciphertext:", ciphertext)

decrypted_text = rc4(key, ciphertext)
print("Decrypted text:", decrypted_text.decode('utf-8'))