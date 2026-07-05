import math

def get_key_matrix(key, size):
    key_matrix = [[0] * size for _ in range(size)]
    k = 0
    for i in range(size):
        for j in range(size):
            key_matrix[i][j] = (ord(key[k]) - ord('a')) % 26
            k += 1
    return key_matrix

def encrypt(cipher_vector, key_matrix, message_vector, size):
    for i in range(size):
        cipher_vector[i] = sum(key_matrix[i][j] * message_vector[j] for j in range(size)) % 26

def decrypt(plain_vector, inverse_key_matrix, cipher_vector, size):
    for i in range(size):
        plain_vector[i] = sum(inverse_key_matrix[i][j] * cipher_vector[j] for j in range(size)) % 26

def mod_inverse(determinant, mod):
    for x in range(1, mod):
        if (determinant * x) % mod == 1:
            return x
    return -1

def determinant(matrix, size):
    if size == 2:
        return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) % 26
    raise ValueError("Matrix size not supported for determinant calculation")

def inverse_key_matrix(key_matrix, size):
    det = determinant(key_matrix, size)
    det = (det + 26) % 26
    det_mod_inverse = mod_inverse(det, 26)
    if det_mod_inverse == -1:
        raise ArithmeticError("Key matrix is not invertible modulo 26")

    inverse_matrix = [[0] * size for _ in range(size)]
    if size == 2:
        inverse_matrix[0][0] = (key_matrix[1][1] * det_mod_inverse) % 26
        inverse_matrix[1][1] = (key_matrix[0][0] * det_mod_inverse) % 26
        inverse_matrix[0][1] = (-key_matrix[0][1] + 26) * det_mod_inverse % 26
        inverse_matrix[1][0] = (-key_matrix[1][0] + 26) * det_mod_inverse % 26
    else:
        raise ValueError("Matrix inversion supports only 2x2 matrices")

    return inverse_matrix

def main():
    message = input("Enter the message: ").lower().replace(" ", "").replace("[^a-z]", "")
    key = input("Enter the key: ").lower().replace(" ", "").replace("[^a-z]", "")

    size = int(math.sqrt(len(key)))
    if size * size != len(key):
        print("Error: Key length must be a perfect square.")
        return

    key_matrix = get_key_matrix(key, size)

    while len(message) % size != 0:
        message += 'x'

    cipher_text = []
    for block in range(0, len(message), size):
        message_vector = [ord(message[i]) - ord('a') for i in range(block, block + size)]
        cipher_vector = [0] * size
        encrypt(cipher_vector, key_matrix, message_vector, size)
        cipher_text.extend([chr(i + ord('a')) for i in cipher_vector])

    print("Cipher Text: ", ''.join(cipher_text))

    inverse_key = inverse_key_matrix(key_matrix, size)

    plain_text = []
    for block in range(0, len(cipher_text), size):
        cipher_vector = [ord(cipher_text[i]) - ord('a') for i in range(block, block + size)]
        plain_vector = [0] * size
        decrypt(plain_vector, inverse_key, cipher_vector, size)
        plain_text.extend([chr(i + ord('a')) for i in plain_vector])

    print("Decrypted Text: ", ''.join(plain_text).rstrip('x'))

main()
