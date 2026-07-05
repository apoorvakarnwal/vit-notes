#Name- 
#Reg No-

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
    print(f"Verification: {a} * {s0} + {b} * {t0} = {a * s0 + b * t0}")

    return r0, s0, t0

a = int(input("Enter the first number (a): "))
b = int(input("Enter the second number (b): "))

d, s, t = extended_euclidean_algorithm(a, b)

