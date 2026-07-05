#Name- Niyati Kumaria
#Reg No-22BCE2017

def is_prime(n):
    if n <= 1:
        return False
    if n == 2 or n == 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True


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


def multiplicative_inverse_fermat(a, p):
    if not is_prime(p):
        print(f"Modulus {p} is not a prime number. Fermat's inverse cannot be applied.")
        return None
    if p <= 1:
        print("Modulus must be a prime number greater than 1.")
        return None
    if a % p == 0:
        print("Inverse does not exist because a is divisible by p.")
        return None

    inverse = modular_exponentiation(a, p - 2, p)
    print(f"Multiplicative inverse of {a} mod {p} is {inverse}")
    return inverse

a = int(input("Enter the number (a): "))
p = int(input("Enter the prime modulus (p): "))

inverse = multiplicative_inverse_fermat(a, p)


