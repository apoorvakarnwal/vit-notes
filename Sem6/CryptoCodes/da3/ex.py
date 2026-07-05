
# def rsa_key_generation(p, q, e):
#     phi=(p-1)*(q-1)
#     d=pow(e,-1,phi)
#     n=p*q
#     return (e,n), (d,n)

# def rsa_encrypt(plaintext, public_key):
#     e,n=public_key
#     plaintext=plaintext.lower()
#     num=[ord(c)-ord('a') if c.isalpha() else ord(c) for c in plaintext]
#     cipher=[pow(c, e, n) for c in num]
#     return ''.join(map(chr, cipher))



# p = int(input("Enter a prime number p: "))
# q = int(input("Enter a prime number q: "))
# e = int(input("Enter a value for e (should be coprime with φ(n)): "))
# plaintext = input("Enter plaintext message: ")

# public_key, private_key = rsa_key_generation(p, q, e)

# print("\nRSA Public Key (e, n):", public_key)
# print("RSA Private Key (d, n):", private_key)

# ciphertext = rsa_encrypt(plaintext, public_key)
# print("\nCiphertext:", ciphertext)

# decrypted_text = rsa_decrypt(ciphertext, private_key)
# print("Decrypted Text:", decrypted_text)



def ksa(key):
    s=[i for i in range(256)]
    j=0
    for i in range(256):
        T=key[i%len(key)]
        j=(j+s[i]+T)%256
        s[i],s[j]=s[j],s[i]
    return s

def prga(s):
    i=0
    j=0
    while True:
        i=(i+1)%256
        j=(j+s[i])%256
        s[i],s[j]=s[j],s[i]
        t=(s[i]+s[j])%256
        yield s[t]


def rc4_encrypt(plaintext, key):
    plaintext_bytes=[ord(c) for c in plaintext]
    key_bytes=[ord(c) for c in key]

    sbox=ksa( key_bytes)
    key_stream=prga(sbox)

    ciphertext=''
    for c in plaintext_bytes:
        ciphertext+= chr(c^next(key_stream) )
    return ciphertext

def rc4_decrypt(ciphertext, key):
    ciphertext_bytes=[ord(c) for c in ciphertext]
    key_bytes=[ord(c) for c in key]

    sbox=ksa(key_bytes)
    key_stream=prga(sbox)

    plaintext=''
    for c in ciphertext_bytes:
        plaintext+= chr(c^next(key_stream) )
    return plaintext



    
plaintext = input('Enter your plaintext: ')
key = input('Enter your secret key: ')

ciphertext = rc4_encrypt(plaintext, key)
print('Encrypted Text: ')
print(ciphertext)

decrypted_text = rc4_decrypt(ciphertext, key)
print('Decrypted Text: ')
print(decrypted_text)