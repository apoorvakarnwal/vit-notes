#Name- Niyati Kumaria
#Reg No-22BCE2017

def extended_euclidean_algorithm(a, b):
    r0, r1 = a, b
    s0, s1 = 1, 0
    t0, t1 = 0, 1

    print(f"Initial setup:")
    print(f"r0 = {r0}, s0 = {s0}, t0 = {t0}")
    print(f"r1 = {r1}, s1 = {s1}, t1 = {t1}")

    step = 1
    while r1 != 0:
        q = r0 // r1
        r = r0 % r1

        s = s0 - q * s1
        t = t0 - q * t1

        print(f"Step {step}:")
        print(f"q = {q}, r = {r}, s = {s}, t = {t}")

        r0, r1 = r1, r
        s0, s1 = s1, s
        t0, t1 = t1, t

        step += 1

    print(f"Final result:")
    print(f"gcd({a}, {b}) = {r0}")
    print(f"s = {s0}, t = {t0}")

    return r0, s0, t0


def multiplicative_inverse(a, m):
    gcd, s, t = extended_euclidean_algorithm(a, m)
    if gcd != 1:
        print(f"Inverse does not exist because gcd({a}, {m}) = {gcd} != 1")
        return None
    else:
        inverse = s % m
        print(f"Multiplicative inverse of {a} mod {m} is {inverse}")
        return inverse


a = int(input("Enter the number (a): "))
m = int(input("Enter the modulus (m): "))

inverse = multiplicative_inverse(a, m)


