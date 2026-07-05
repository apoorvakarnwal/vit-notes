def p_box(input_bits, permutation_table):
    output_bits = ""
    for position in permutation_table:
        output_bits += input_bits[position - 1]  
    return output_bits


def s_box(input_bits, substitution_table):
    return substitution_table.get(input_bits, "0000")  

if __name__ == "__main__":
    input_bits = "11001010"

    permutation_table = [4, 1, 3, 2, 8, 7, 6, 5]  
    permuted_bits = p_box(input_bits, permutation_table)
    print(f"Input bits: {input_bits}")
    print(f"Permuted bits (P-box): {permuted_bits}")

    substitution_table = {
        "0000": "1110",
        "0001": "0100",
        "0010": "1101",
        "0011": "0001",
        "0100": "0010",
        "0101": "1111",
        "0110": "1011",
        "0111": "1000",
        "1000": "0011",
        "1001": "1010",
        "1010": "0110",
        "1011": "1100",
        "1100": "0101",
        "1101": "1001",
        "1110": "0000",
        "1111": "0111",
    }
    s_box_input = "1010"  
    substituted_bits = s_box(s_box_input, substitution_table)
    print(f"S-box input: {s_box_input}")
    print(f"Substituted bits (S-box): {substituted_bits}")