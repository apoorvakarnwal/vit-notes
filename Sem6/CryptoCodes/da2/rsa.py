
def mod_inverse(e, phi):
    return pow(e, -1, phi)

def rsa_key_generation(p, q, e):
    n = p * q
    phi = (p - 1) * (q - 1)
    d = mod_inverse(e, phi)
    return (e, n), (d, n)

def rsa_encrypt(plaintext, public_key):
    e, n = public_key
    plaintext=plaintext.lower()
    numbers = [(ord(c) - ord('a')) if c.isalpha() else ord(c) for c in plaintext]
    ciphertext = [pow(num, e, n) for num in numbers]
    return ciphertext

def rsa_decrypt(ciphertext, private_key):
    d, n = private_key
    numbers = [pow(c, d, n) for c in ciphertext]
    plaintext = ''.join([chr(num + ord('a')) if 0 <= num <= 25 else chr(num) for num in numbers])
    return plaintext

p = int(input("Enter a prime number p: "))
q = int(input("Enter a prime number q: "))
e = int(input("Enter a value for e (should be coprime with φ(n)): "))
plaintext = input("Enter plaintext message: ")

public_key, private_key = rsa_key_generation(p, q, e)

print("\nRSA Public Key (e, n):", public_key)
print("RSA Private Key (d, n):", private_key)

ciphertext = rsa_encrypt(plaintext, public_key)
print("\nCiphertext:", ciphertext)

decrypted_text = rsa_decrypt(ciphertext, private_key)
print("Decrypted Text:", decrypted_text)