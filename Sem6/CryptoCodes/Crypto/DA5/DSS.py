#Name- Niyati Kumaria
#Reg No- 22BCE2017

def modinv(a, m):
    def extended_gcd(a, b):
        if a == 0:
            return (b, 0, 1)
        else:
            g, y, x = extended_gcd(b % a, a)
            return (g, x - (b // a) * y, y)
    g, x, y = extended_gcd(a, m)
    if g != 1:
        return None  
    else:
        return x % m


def main():
    p = int(input("Enter prime modulus p: "))
    q = int(input("Enter prime divisor q of (p-1): "))
    h = int(input("Enter h (where 1 < h < p-1): "))
    k = int(input("Enter k (random number where 0 < k < q): "))
    x = int(input("Enter private key x (where 0 < x < q): "))
    hM = int(input("Enter h(M) (hash of the message): "))
    
    g = pow(h, (p-1)//q, p)
    
    y = pow(g, x, p)
    
    r = pow(g, k, p) % q
    if r == 0:
        print("Error: r cannot be 0, choose different k")
        return
    
    k_inv = modinv(k, q)
    if k_inv is None:
        print("Error: k has no modular inverse mod q, choose different k")
        return
    
    s = (k_inv * (hM + x * r)) % q
    if s == 0:
        print("Error: s cannot be 0, choose different k")
        return
    
    w = modinv(s, q)
    if w is None:
        print("Error: s has no modular inverse mod q, signature invalid")
        return
    
    u1 = (hM * w) % q
    u2 = (r * w) % q
    
    v = (pow(g, u1, p) * pow(y, u2, p)) % p % q
    verification = "Accepted" if v == r else "Rejected"

    print(f"1. Generator g: {g}")
    print(f"2. Public key y: {y}")
    print(f"3. Signature (r, s): ({r}, {s})")
    print(f"4. Verification components (u1, u2): ({u1}, {u2})")
    print(f"5. Verification: {verification}")

if __name__ == "__main__":
    main()
