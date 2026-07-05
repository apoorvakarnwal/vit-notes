def pad_text(text, size):
    return text + 'X' * ((size - len(text)) % size)

def row_transposition_encrypt(text, key):
    width = len(text) // len(key)
    matrix = [text[i * width: (i + 1) * width] for i in range(len(key))]

    sorted_indices = sorted(range(len(key)), key=lambda k: key[k])

    return ''.join(''.join(matrix[i])  for i in sorted_indices)


def row_transposition_decrypt(ciphertext, key):
    width = len(ciphertext) // len(key)
    matrix = [ciphertext[i * width:(i + 1) * width] for i in range(len(key))]

    inverse_key = sorted(range(len(key)), key=lambda k: key[k])
    decrypted_matrix = [matrix[i] for i in inverse_key]

    return ''.join(''.join(row) for row in decrypted_matrix).rstrip('X')


def column_transposition_encrypt(text, key):
    width = len(key)
    height = len(text) // len(key)
    
    matrix = [text[i * width:(i + 1) * width] for i in range(height)]

    sorted_indices = sorted(range(len(key)), key=lambda k: key[k])
    encrypted_text = ''.join(''.join(row[i] for row in matrix) for i in sorted_indices)

    return encrypted_text


def column_transposition_decrypt(text, key):
    width, height = len(key), len(text) // len(key)
    matrix = [[''] * width for _ in range(height)]

    col_order = sorted(range(len(key)), key=lambda k: key[k])

    pos = 0
    for i in col_order:
        for row in range(height):
            matrix[row][i] = text[pos]
            pos += 1

    return ''.join(''.join(row) for row in matrix).rstrip('X')

if __name__ == "__main__":
    message = input("Enter the message: ").upper()
    row_key = [1,2,3]
    col_key = [1,2,3]
    message=pad_text(message, len(row_key))

    row_enc = row_transposition_encrypt(message, row_key)
    row_dec = row_transposition_decrypt(row_enc, row_key)

    col_enc = column_transposition_encrypt(message, col_key)
    col_dec = column_transposition_decrypt(col_enc, col_key)

    print(f"Original: {message}")
    print(f"Row Transposition Encrypted: {row_enc}")
    print(f"Row Transposition Decrypted: {row_dec}")
    print(f"\nColumn Transposition Encrypted: {col_enc}")
    print(f"Column Transposition Decrypted: {col_dec}")
