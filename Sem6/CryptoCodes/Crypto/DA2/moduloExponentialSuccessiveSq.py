#Name- Niyati Kumaria
#Reg No-22BCE2017

def modulo_exponentiation(base, exponent, mod):
    binary_exponent = bin(exponent)[2:]  

    powers = {}
    current_power = 1
    current_value = base % mod
    powers[current_power] = current_value
    print(f"{base}^{current_power} mod {mod} = {current_value}")

    while current_power * 2 <= exponent:
        current_power *= 2
        current_value = (current_value * current_value) % mod
        powers[current_power] = current_value
        print(f"{base}^{current_power} mod {mod} = {current_value}")

    result = 1
    print("\nMultiplying the required powers:")
    for power, value in powers.items():
        if (exponent & power) != 0:  
            print(f"{base}^{power} mod {mod} = {value}")
            result = (result * value) % mod

    print(f"\nFinal result: {base}^{exponent} mod {mod} = {result}")
    return result


base = int(input("Enter the base: "))
exponent = int(input("Enter the exponent: "))
mod = int(input("Enter the modulus: "))

modulo_exponentiation(base, exponent, mod)
