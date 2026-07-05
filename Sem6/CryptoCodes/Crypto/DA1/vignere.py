def encrypt(plaintext, keyword):
    ciphertext = []
    extended_keyword = extend_keyword(keyword, len(plaintext))
    
    for i in range(len(plaintext)):
        plain_char = plaintext[i]
        key_char = extended_keyword[i]
        
        encrypted_char = chr((ord(plain_char) + ord(key_char) - 2 * ord('A')) % 26 + ord('A'))
        ciphertext.append(encrypted_char)
    
    return ''.join(ciphertext)

def decrypt(ciphertext, keyword):
    plaintext = []
    extended_keyword = extend_keyword(keyword, len(ciphertext))
    
    for i in range(len(ciphertext)):
        cipher_char = ciphertext[i]
        key_char = extended_keyword[i]
        
        decrypted_char = chr((ord(cipher_char) - ord(key_char) + 26) % 26 + ord('A'))
        plaintext.append(decrypted_char)
    
    return ''.join(plaintext)

def extend_keyword(keyword, length):
    extended_keyword = []
    for i in range(length):
        extended_keyword.append(keyword[i % len(keyword)])
    
    return ''.join(extended_keyword)

plaintext = input("Enter text: ").upper().replace(" ", "").replace("[^A-Z]", "")
keyword = input("Enter keyword: ").upper().replace(" ", "").replace("[^A-Z]", "")
    
ciphertext = encrypt(plaintext, keyword)
print("Encrypted: ",ciphertext)
    
decrypted_text = decrypt(ciphertext, keyword)
print("Decrypted: ",decrypted_text)

