#Name-
#Reg No- 22BCE

def mod_exp(base, exponent, mod):
    result = 1
    base = base % mod
    while exponent > 0:
        if exponent % 2 == 1:
            result = (result * base) % mod
        exponent = exponent >> 1
        base = (base * base) % mod
    return result

def elgamal_key_generation(q, alpha, XA):
    YA = mod_exp(alpha, XA, q)
    public_key = (q, alpha, YA)
    return public_key

def elgamal_encryption(q, alpha, YA, k, plaintext):
    C1 = mod_exp(alpha, k, q)
    C2 = (plaintext * mod_exp(YA, k, q)) % q
    ciphertext = (C1, C2)
    return ciphertext

def elgamal_decryption(q, XA, ciphertext):
    C1, C2 = ciphertext
    s = mod_exp(C1, XA, q)
    s_inv = mod_exp(s, q - 2, q)  
    plaintext = (C2 * s_inv) % q
    return plaintext

q = int(input("Enter the value of q: "))
alpha = int(input("Enter the value of alpha: "))
XA = int(input("Enter the value of XA: "))
k = int(input("Enter the value of k (random integer): "))
plaintext = int(input("Enter the plaintext: "))

public_key = elgamal_key_generation(q, alpha, XA)
YA = public_key[2]
print("Public Key (q, alpha, YA):", public_key)

ciphertext = elgamal_encryption(q, alpha, YA, k, plaintext)
print("Ciphertext (C1, C2):", ciphertext)

decrypted_plaintext = elgamal_decryption(q, XA, ciphertext)
print("Decrypted Plaintext:", decrypted_plaintext)

