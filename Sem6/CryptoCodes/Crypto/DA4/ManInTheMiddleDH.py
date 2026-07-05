#Name- 
#Reg No- 22BCE

def mod_exp(base, exp, mod):
    result = 1
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result

q = int(input("Enter prime number q: "))
alpha = int(input("Enter primitive root alpha: "))
XA = int(input("Enter Alice's private key XA: "))
XB = int(input("Enter Bob's private key XB: "))
XDA = int(input("Enter Attacker's private key XDA: "))
XDB = int(input("Enter Attacker's private key XDB: "))

YA = mod_exp(alpha, XA, q)
YB = mod_exp(alpha, XB, q)
YDA = mod_exp(alpha, XDA, q)  
YDB = mod_exp(alpha, XDB, q)  

KDA_attacker = mod_exp(YA, XDA, q)
KDB_attacker = mod_exp(YB, XDB, q)
print(f"Attacker computes shared key with Alice (KDA): {KDA_attacker}")
print(f"Attacker computes shared key with Bob (KDB): {KDB_attacker}")