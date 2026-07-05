#Name- Niyati Kumaria
#Reg No-22BCE2017

import math

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def euler_totient(n):
    result = n
    p = 2
    while p * p <= n:
        if n % p == 0:
            while n % p == 0:
                n = n // p
            result -= result // p
        p += 1
    if n > 1:
        result -= result // n
    return result


def modular_exponentiation(base, exponent, mod):
    result = 1
    base = base % mod
    print(f"Initial setup: {base}^{exponent} mod {mod}")

    while exponent > 0:
        if exponent % 2 == 1:
            result = (result * base) % mod
            
        base = (base * base) % mod
        exponent = exponent // 2

    print(f"Final result: {result}")
    return result


def multiplicative_inverse_euler(a, n):
    if gcd(a, n) != 1:
        print(f"Inverse does not exist because gcd({a}, {n}) != 1")
        return None

    phi_n = euler_totient(n)
    print(f"Euler's Totient Function phi({n}) = {phi_n}")

    inverse = modular_exponentiation(a, phi_n - 1, n)
    print(f"Multiplicative inverse of {a} mod {n} is {inverse}")
    return inverse

a = int(input("Enter the number (a): "))
n = int(input("Enter the modulus (n): "))

inverse = multiplicative_inverse_euler(a, n)


