#Name- Niyati Kumaria
#Reg No-22BCE2017

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def extended_euclidean_algorithm(a, b):
    r0, r1 = a, b
    s0, s1 = 1, 0
    t0, t1 = 0, 1

    while r1 != 0:
        q = r0 // r1
        r0, r1 = r1, r0 % r1
        s0, s1 = s1, s0 - q * s1
        t0, t1 = t1, t0 - q * t1

    return r0, s0, t0


def modular_inverse(a, m):
    gcd_val, s, t = extended_euclidean_algorithm(a, m)
    if gcd_val != 1:
        raise ValueError(f"Inverse does not exist because gcd({a}, {m}) != 1")
    return s % m


def chinese_remainder_theorem(a_list, m_list):
    for i in range(len(m_list)):
        for j in range(i + 1, len(m_list)):
            if gcd(m_list[i], m_list[j]) != 1:
                raise ValueError("Moduli are not pairwise coprime. CRT cannot be applied.")

    M = 1
    for m in m_list:
        M *= m

    x = 0
    for i in range(len(a_list)):
        M_i = M // m_list[i]
        y_i = modular_inverse(M_i, m_list[i])
        x += a_list[i] * M_i * y_i

    return x % M

n = int(input("Enter the number of congruences: "))
a_list = []
m_list = []

for i in range(n):
    a = int(input(f"Enter a_{i+1}: "))
    m = int(input(f"Enter m_{i+1}: "))
    a_list.append(a)
    m_list.append(m)

try:
    solution = chinese_remainder_theorem(a_list, m_list)
    print(f"The solution to the system of congruences is: {solution}")
except ValueError as e:
    print(e)


