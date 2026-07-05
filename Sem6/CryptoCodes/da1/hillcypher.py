import numpy as np
from numpy.linalg import inv, det

def text_to_numbers(text):
    return [ord(c) - ord('A') for c in text]

def numbers_to_text(numbers):
    return ''.join(chr(n + ord('A')) for n in numbers)

def matrix_mod_inverse(matrix, modulus):
    determinant = int(round(det(matrix)))
    det_inverse = pow(determinant, -1, modulus)
    adjugate = np.round(determinant * inv(matrix)).astype(int)
    return np.mod(det_inverse * adjugate, modulus)

def prepare_text(text, block_size):
    text = ''.join(text)
    while len(text) % block_size != 0:
        text += 'X'  # Padding
    return text

def hill_encrypt(plaintext, key):
    key_matrix = np.array(key)
    block_size = len(key_matrix)
    plaintext = prepare_text(plaintext, block_size)
    numbers = text_to_numbers(plaintext)
    vectors = np.array_split(numbers, len(numbers) // block_size)
    encrypted_numbers = [np.dot(key_matrix, vec) % 26 for vec in vectors]
    return numbers_to_text(np.concatenate(encrypted_numbers))

def hill_decrypt(ciphertext, key):
    key_matrix = np.array(key)
    inverse_matrix = matrix_mod_inverse(key_matrix, 26)
    block_size = len(key_matrix)
    numbers = text_to_numbers(ciphertext)
    vectors = np.array_split(numbers, len(numbers) // block_size)
    decrypted_numbers = [np.dot(inverse_matrix, vec) % 26 for vec in vectors]
    return numbers_to_text(np.concatenate(decrypted_numbers)).rstrip('X')

if __name__ == "__main__":
    message = input("Enter message: ").upper()
    key_string = input("Enter key string: ").upper().replace(" ", "")
    size = int(len(key_string) ** 0.5)
    key_matrix = np.array([ord(c) - ord('A') for c in key_string]).reshape(size, size)

    encrypted = hill_encrypt(message, key_matrix)
    print(f"Encrypted: {encrypted}")
    decrypted = hill_decrypt(encrypted, key_matrix)
    print(f"Decrypted: {decrypted}")
