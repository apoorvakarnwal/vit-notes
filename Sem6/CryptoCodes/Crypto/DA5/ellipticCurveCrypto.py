#Name- Niyati Kumaria
#Reg No- 22BCE2017

def ecc_encrypt(P, M, a, b, G, nB, k):
    def point_add(P1, P2):
        if P1 == (0, 0):
            return P2
        if P2 == (0, 0):
            return P1
        if P1[0] == P2[0] and P1[1] != P2[1]:
            return (0, 0)  
        
        if P1 != P2:
            lam = (P2[1] - P1[1]) * pow(P2[0] - P1[0], -1, P) % P
        else:
            lam = (3 * P1[0]*P1[0] + a) * pow(2 * P1[1], -1, P) % P
        
        x3 = (lam*lam - P1[0] - P2[0]) % P
        y3 = (lam*(P1[0] - x3) - P1[1]) % P
        return (x3, y3)
    
    def scalar_mult(k, point):
        result = (0, 0) 
        current = point
        
        while k > 0:
            if k % 2 == 1:
                result = point_add(result, current)
            current = point_add(current, current)
            k = k // 2
        return result
    
    PublicKey = scalar_mult(nB, G)
    
    kG = scalar_mult(k, G)
    
    kPb = scalar_mult(k, PublicKey)
    
    cipher_point = point_add(M, kPb)
    
    return (PublicKey, (kG, cipher_point))

def get_point_input(prompt, P):
    while True:
        try:
            x, y = map(int, input(prompt).strip().split())
            if 0 <= x < P and 0 <= y < P:
                return (x, y)
            print(f"Coordinates must be between 0 and {P-1}")
        except ValueError:
            print("Please enter two integers separated by space")

def get_int_input(prompt, min_val=0):
    while True:
        try:
            val = int(input(prompt))
            if val >= min_val:
                return val
            print(f"Value must be ≥ {min_val}")
        except ValueError:
            print("Please enter a valid integer")

def main():
    P = get_int_input("Enter prime P for the finite field GF(P): ", 2)
    
    print("Enter coefficients for the elliptic curve:")
    a = get_int_input("a: ")
    b = get_int_input("b: ")
    
    print("Enter base point G (generator):")
    G = get_point_input("G (x y): ", P)
    
    nB = get_int_input("Enter private key nB: ", 1)
    
    print("Enter message point M to encrypt:")
    M = get_point_input("M (x y): ", P)
    
    k = get_int_input("Enter random integer k for encryption: ", 1)
    
    PublicKey, ciphertext = ecc_encrypt(P, M, a, b, G, nB, k)
    
    print(f"\nGenerated public key (nB*G): {PublicKey}")
    print(f"Ciphertext: {ciphertext}")

if __name__ == "__main__":
    main()


    