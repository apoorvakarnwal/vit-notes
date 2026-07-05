def mod_exp(base, exp, mod):
    """Modular exponentiation using the fast exponentiation method."""
    result = 1
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result

# Input
q = int(input("Enter prime number q: "))
alpha = int(input("Enter primitive root alpha: "))
XA = int(input("Enter Alice's private key XA: "))
XB = int(input("Enter Bob's private key XB: "))
XDA = int(input("Enter Attacker's private key XDA: "))
XDB = int(input("Enter Attacker's private key XDB: "))

# Public keys
YA = mod_exp(alpha, XA, q)  # Alice's public key
YB = mod_exp(alpha, XB, q)  # Bob's public key

# Attacker's public keys
YDA = mod_exp(alpha, XDA, q)  # Attacker's public key for Alice
YDB = mod_exp(alpha, XDB, q)  # Attacker's public key for Bob

# Shared keys
KDA = mod_exp(YDB, XA, q)  # Alice computes shared key with attacker
KDB = mod_exp(YDA, XB, q)  # Bob computes shared key with attacker

# Attacker computes shared keys
KDA_attacker = mod_exp(YA, XDB, q)  # Attacker's shared key with Alice
KDB_attacker = mod_exp(YB, XDA, q)  # Attacker's shared key with Bob

# Output
print(f"Alice's Public Key (YA): {YA}")
print(f"Bob's Public Key (YB): {YB}")
print(f"Attacker's Public Key for Alice (YDA): {YDA}")
print(f"Attacker's Public Key for Bob (YDB): {YDB}")
print(f"Shared Key between Alice and Attacker (KDA): {KDA}")
print(f"Shared Key between Bob and Attacker (KDB): {KDB}")
print(f"Attacker computes shared key with Alice (KDA_attacker): {KDA_attacker}")
print(f"Attacker computes shared key with Bob (KDB_attacker): {KDB_attacker}")