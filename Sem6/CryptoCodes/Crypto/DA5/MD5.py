#Name- Niyati Kumaria
#Reg No- 22BCE2017

def F(x, y, z):
    return (x & y) | (~x & z)

def G(x, y, z):
    return (x & z) | (y & ~z)

def H(x, y, z):
    return x ^ y ^ z

def I(x, y, z):
    return y ^ (x | ~z)

# Function to take hex input and convert to integer
def get_input(label):
    return int(input(f"Enter value for {label} (hexadecimal): "), 16)

A = get_input("A")
B = get_input("B")
C = get_input("C")
D = get_input("D")

# Calculating outputs
f = F(B, C, D) & 0xFFFFFFFF
g = G(B, C, D) & 0xFFFFFFFF
h = H(B, C, D) & 0xFFFFFFFF
i = I(B, C, D) & 0xFFFFFFFF

# Displaying results in hex
print("\nOutput:")
print(f"F: {f:08X}")
print(f"G: {g:08X}")
print(f"H: {h:08X}")
print(f"I: {i:08X}")

