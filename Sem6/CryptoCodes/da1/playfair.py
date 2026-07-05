SIZE = 5

def generate_matrix(key):
    key = key.replace('J', 'I')
    seen = set()
    matrix = []
    for c in key:
        if c not in seen:
            seen.add(c)
            matrix.append(c)
    for c in 'ABCDEFGHIKLMNOPQRSTUVWXYZ':
        if c not in seen:
            matrix.append(c)
    return [matrix[i * SIZE:(i + 1) * SIZE] for i in range(SIZE)]

def prepare_text(text):
    text = text.replace('J', 'I').replace(' ', '')
    prepared = []
    i = 0
    while i < len(text):
        if i == len(text) - 1: 
            prepared.append(text[i])
            i += 1
        elif text[i] == text[i + 1]: 
            prepared.append(text[i])
            prepared.append('X')
            i += 1
        else:  # Different pair
            prepared.append(text[i])
            prepared.append(text[i + 1])
            i += 2
    # Ensure even length
    if len(prepared) % 2 != 0:
        prepared.append('X')
    return ''.join(prepared)


def find_position(matrix, c):
    for row in range(SIZE):
        for col in range(SIZE):
            if matrix[row][col] == c:
                return row, col

def encrypt(plaintext, matrix):
    plaintext = prepare_text(plaintext)
    print(f"Prepared: {plaintext}")
    ciphertext = []
    for i in range(0, len(plaintext), 2):
        a, b = plaintext[i], plaintext[i + 1]
        row_a, col_a = find_position(matrix, a)
        row_b, col_b = find_position(matrix, b)
        if row_a == row_b:
            ciphertext.append(matrix[row_a][(col_a + 1) % SIZE])
            ciphertext.append(matrix[row_b][(col_b + 1) % SIZE])
        elif col_a == col_b:
            ciphertext.append(matrix[(row_a + 1) % SIZE][col_a])
            ciphertext.append(matrix[(row_b + 1) % SIZE][col_b])
        else:
            ciphertext.append(matrix[row_a][col_b])
            ciphertext.append(matrix[row_b][col_a])
    return ''.join(ciphertext)

def decrypt(ciphertext, matrix):
    plaintext = []
    for i in range(0, len(ciphertext), 2):
        a, b = ciphertext[i], ciphertext[i + 1]
        row_a, col_a = find_position(matrix, a)
        row_b, col_b = find_position(matrix, b)
        if row_a == row_b:
            plaintext.append(matrix[row_a][(col_a - 1) % SIZE])
            plaintext.append(matrix[row_b][(col_b - 1) % SIZE])
        elif col_a == col_b:
            plaintext.append(matrix[(row_a - 1) % SIZE][col_a])
            plaintext.append(matrix[(row_b - 1) % SIZE][col_b])
        else:
            plaintext.append(matrix[row_a][col_b])
            plaintext.append(matrix[row_b][col_a])
    return ''.join(plaintext)

plaintext = input("Enter the plaintext: ").upper().replace(' ', '')
key = input("Enter the key: ").upper().replace(' ', '')
matrix = generate_matrix(key)
print("\nKey Matrix:")
for row in matrix:
    print(' '.join(row))

encrypted_text = encrypt(plaintext, matrix)
print("Encrypted Text:", encrypted_text)
decrypted_text = decrypt(encrypted_text, matrix)
print("Decrypted Text:", decrypted_text)