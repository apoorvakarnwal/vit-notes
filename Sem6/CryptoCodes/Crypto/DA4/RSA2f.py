#Name- 
#Reg No- 22BCE

def modinv(a,m):
    def gcdExt(a,b):
        if(a == 0):
            return b,0,1
        else:
            g, x1, y1 = gcdExt(b % a, a)
            x = y1 - (b // a)* x1
            y = x1
            return g, x, y
    g,x,y=gcdExt(a,m)
    if(g != 1):
        return None
    return (x % m + m) % m

def generate_rsa_private_key(p, q, e):
    n = p * q
    phi = (p - 1) * (q - 1)
    d = modinv(e, phi)
    private_key = (d, n)
    
    return private_key

def rsa_encrypt(plaintext, e, n):
    if isinstance(plaintext, list):
        return [pow(m, e, n) for m in plaintext]
    else:
        return pow(plaintext, e, n)

def rsa_decrypt(ciphertext, d, n):
    if isinstance(ciphertext, list):
        return [pow(c, d, n) for c in ciphertext]
    else:
        return pow(ciphertext, d, n)

p = int(input("Enter the value of p: "))
q = int(input("Enter the value of q: "))
e = int(input("Enter the value of e: "))
plaintext = input("Enter the plaintext (a number or a list of numbers in []): ")

try:
    plaintext = eval(plaintext)  
except:
    plaintext = int(plaintext)  

try:
    private_key = generate_rsa_private_key(p, q, e)
    d, n = private_key
    print("Private Key (d, n):", private_key)
    
    ciphertext = rsa_encrypt(plaintext, e, n)
    print("Ciphertext:", ciphertext)
    
    decrypted_plaintext = rsa_decrypt(ciphertext, d, n)
    print("Decrypted Plaintext:", decrypted_plaintext)
except Exception as e:
    print("Error:", e)

