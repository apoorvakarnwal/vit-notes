#Name- 
#Reg No- 22BCE

def extended_gcd(a, b):
    if a == 0:
        return b, 0, 1
    else:
        g, y, x = extended_gcd(b % a, a)
        return g, x - (b // a) * y, y

def modinv(e, phi):
    g, x, y = extended_gcd(e, phi)
    if g != 1:
        raise Exception('Modular inverse does not exist')
    else:
        return x % phi

def generate_rsa_private_key(p, q, e):
    n = p * q
    phi = (p - 1) * (q - 1)
    d = modinv(e, phi)
    private_key = (d, n)
    
    return private_key

p = int(input("Enter the value of p: "))
q = int(input("Enter the value of q: "))
e = int(input("Enter the value of e: "))

try:
    private_key = generate_rsa_private_key(p, q, e)
    print("Private Key (d, n):", private_key)
except Exception as e:
    print("Error:", e)

