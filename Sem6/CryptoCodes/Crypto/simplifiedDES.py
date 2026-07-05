# Simplified DES (Data Encryption Standard) Implementation

# Initial Permutation (IP) table
IP = [1, 5, 2, 0, 3, 7, 4, 6]

# Inverse Initial Permutation (IP^-1) table
IP_INV = [3, 0, 2, 4, 6, 1, 7, 5]

# Expansion Permutation (E) table
E = [3, 0, 1, 2, 1, 2, 3, 0]

# Permutation (P) table
P = [1, 0, 3, 2]

# S-Boxes (Simplified)
S0 = [
    [1, 0, 3, 2],
    [3, 2, 1, 0],
    [0, 2, 1, 3],
    [3, 1, 0, 2]
]

S1 = [
    [0, 1, 2, 3],
    [2, 3, 1, 0],
    [3, 0, 1, 2],
    [2, 1, 0, 3]
]

# Key generation (10-bit key)
def generate_keys(key):
    # Permutation (P10) table
    P10 = [2, 4, 1, 6, 3, 9, 0, 8, 7, 5]

    # Permutation (P8) table
    P8 = [5, 2, 6, 3, 7, 4, 9, 8]

    # Apply P10 permutation
    key = [key[P10[i]] for i in range(10)]

    # Split into left and right
    left = key[:5]
    right = key[5:]

    # Left shift (LS-1)
    left = left[1:] + left[:1]
    right = right[1:] + right[:1]

    # Combine and apply P8 permutation to get K1
    combined = left + right
    K1 = [combined[P8[i]] for i in range(8)]

    # Left shift (LS-2)
    left = left[2:] + left[:2]
    right = right[2:] + right[:2]

    # Combine and apply P8 permutation to get K2
    combined = left + right
    K2 = [combined[P8[i]] for i in range(8)]

    return K1, K2

# Initial Permutation (IP)
def initial_permutation(block):
    return [block[IP[i]] for i in range(8)]

# Inverse Initial Permutation (IP^-1)
def inverse_initial_permutation(block):
    return [block[IP_INV[i]] for i in range(8)]

# Expansion Permutation (E)
def expansion(block):
    return [block[E[i]] for i in range(8)]

# XOR two lists
def xor(list1, list2):
    return [list1[i] ^ list2[i] for i in range(len(list1))]

# S-Box substitution
def s_box_substitution(block):
    # Split into left and right
    left = block[:4]
    right = block[4:]

    # S0 substitution
    row = left[0] * 2 + left[3]
    col = left[1] * 2 + left[2]
    s0 = S0[row][col]

    # S1 substitution
    row = right[0] * 2 + right[3]
    col = right[1] * 2 + right[2]
    s1 = S1[row][col]

    # Combine and return
    return [s0 // 2, s0 % 2, s1 // 2, s1 % 2]

# Permutation (P)
def permutation(block):
    return [block[P[i]] for i in range(4)]

# F function
def f_function(block, key):
    # Expansion
    expanded = expansion(block)
    # XOR with key
    xored = xor(expanded, key)
    # S-Box substitution
    substituted = s_box_substitution(xored)
    # Permutation
    permuted = permutation(substituted)
    return permuted

# Encrypt a block
def encrypt_block(block, K1, K2):
    # Initial permutation
    block = initial_permutation(block)

    # Split into left and right
    left = block[:4]
    right = block[4:]

    # Round 1
    f_result = f_function(right, K1)
    new_right = xor(left, f_result)
    new_left = right

    # Round 2
    f_result = f_function(new_right, K2)
    final_left = xor(new_left, f_result)
    final_right = new_right

    # Combine and apply inverse initial permutation
    combined = final_left + final_right
    ciphertext = inverse_initial_permutation(combined)

    return ciphertext

# Example usage
if __name__ == "_main_":
    # 10-bit key
    key = [1, 0, 1, 0, 0, 0, 0, 0, 1, 0]

    # 8-bit plaintext
    plaintext = [0, 1, 0, 0, 1, 1, 0, 1]

    # Generate keys
    K1, K2 = generate_keys(key)

    # Encrypt
    ciphertext = encrypt_block(plaintext, K1, K2)
    print("Ciphertext:", ciphertext)