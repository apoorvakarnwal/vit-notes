SHIFTS = [1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1]

pc2 = [
    14, 17, 11, 24,  1,  5,
    3,  28, 15,  6, 21, 10,
    23, 19, 12,  4, 26,  8,
    16,  7, 27, 20, 13,  2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
]

def permute(block, permutation):
    return [block[p-1] for p in permutation]

def bytes_to_bits(data):
    return [int(b) for byte in data for b in f'{byte:08b}']

def bits_to_str(bits):
    return ''.join(str(bit) for bit in bits)

def custom_pc1(key_bits):
    return [bit for i, bit in enumerate(key_bits) if (i + 1) % 8 != 0]

def generate_subkeys(key):
    if len(key) != 8:
        raise ValueError("Key must be 8 bytes long")

    key_bits = bytes_to_bits(key)
    key_56_bits = custom_pc1(key_bits)
    left, right = key_56_bits[:28], key_56_bits[28:]

    subkeys = []
    for shift in SHIFTS:
        left = left[shift:] + left[:shift]
        right = right[shift:] + right[:shift]
        combined = left + right
        subkey = permute(combined, pc2)
        subkeys.append(subkey)

    return subkeys

def main():
    print(bytes('sdfghjkl', 'utf-8'))
    
    original_key = b'sdfghjkl'
    print(original_key)
    subkeys = generate_subkeys(original_key)

    print("Generated 16 Subkeys:")
    for i, subkey in enumerate(subkeys, 1):
        print(f"Round {i}: {bits_to_str(subkey)}")

if __name__ == "__main__":
    main()