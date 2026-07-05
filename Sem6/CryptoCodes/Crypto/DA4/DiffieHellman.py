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

def diffie_hellman_key_exchange(q, alpha, XA, XB):
    YA = mod_exp(alpha, XA, q)  
    YB = mod_exp(alpha, XB, q)  
    key_A = mod_exp(YB, XA, q)  
    key_B = mod_exp(YA, XB, q)  
    if key_A != key_B:
        raise Exception("Error: Shared keys do not match!")
    
    return key_A

q = int(input("Enter the value of q: "))
alpha = int(input("Enter the value of alpha: "))
XA = int(input("Enter the value of XA: "))
XB = int(input("Enter the value of XB: "))

try:
    shared_key = diffie_hellman_key_exchange(q, alpha, XA, XB)
    print("Shared Secret Key:", shared_key)
except Exception as e:
    print(e)

