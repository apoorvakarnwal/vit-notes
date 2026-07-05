#Name- Niyati Kumaria
#Reg No-22BCE2017

def miller_rabin_single_base(n, a):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0:
        return False

    k = 0
    d = n - 1
    while d % 2 == 0:
        d //= 2
        k += 1

    x = pow(a, d, n)
    if x == 1 or x == n - 1:
        return True 

    for _ in range(k - 1):
        x = pow(x, 2, n)
        if x == n - 1:
            return True  

    return False 


n = int(input("Enter the number to test for primality (n): "))
a_input = input("Enter the bases (space-separated integers): ")
a_list = list(map(int, a_input.split()))

is_prime = True
for a in a_list:
    if not miller_rabin_single_base(n, a):
        print(f"{n} fails the Miller-Rabin test with base {a} (composite).")
        is_prime = False
        break
    else:
        print(f"{n} passes the Miller-Rabin test with base {a}.")

if is_prime:
    print(f"{n} is likely prime (passed all tests).")

