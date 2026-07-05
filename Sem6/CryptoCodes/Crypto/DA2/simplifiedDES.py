#Name- Niyati Kumaria
#Reg No-22BCE2017

def p_box(permutation_table, input_bits):
    output_bits = []
    for index in permutation_table:
        output_bits.append(input_bits[index - 1])
    return output_bits

def s_box(substitution_table, input_bits):
    group_size = len(substitution_table[0]).bit_length() - 1
    num_groups = len(input_bits) // group_size
    output_bits = []
    for i in range(num_groups):
        start = i * group_size
        end = start + group_size
        group = input_bits[start:end]
        row = int("".join(map(str, [group[0], group[-1]])), 2)
        col = int("".join(map(str, group[1:-1])), 2)
        substituted_value = substitution_table[row][col]
        output_bits.extend([int(bit) for bit in f"{substituted_value:04b}"])
    return output_bits

if __name__ == "__main__":
    s_box_table = [
        [14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7],
        [0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8],
        [4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0],
        [15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13],
    ]

    p_box_table = [
        16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10,
        2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25,
        40, 39, 38, 37, 36, 35, 34, 33, 64, 63, 62, 61, 60, 59, 58, 57,
        56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41
    ]

    input_bits_sbox = list(map(int, input("Enter 64-bit input for S-box (space-separated): ").split()))

    if len(input_bits_sbox) != 64:
        print("Error: Input must be exactly 64 bits.")
    else:
        substituted_bits = []
        for i in range(0, 64, 4):
            group = input_bits_sbox[i:i+4]
            substituted_group = s_box(s_box_table, group)
            substituted_bits.extend(substituted_group)
        print("S-box output:", " ".join(map(str, substituted_bits)))

        permuted_bits = p_box(p_box_table, substituted_bits)
        print("P-box output:", " ".join(map(str, permuted_bits)))
