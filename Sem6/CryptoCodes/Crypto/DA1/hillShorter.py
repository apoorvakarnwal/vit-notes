def get_key_matrix(key, size):
    key_matrix = [[0] * size for _ in range(size)]
    k = 0
    for i in range(size):
        for j in range(size):
            key_matrix[i][j] = ord(key[k]) % 65
            k += 1
    return key_matrix


def encrypt_message(message_vector, key_matrix, size):
    cipher_matrix = [[0] for _ in range(size)]
    for i in range(size):
        for j in range(1):
            cipher_matrix[i][j] = 0
            for x in range(size):
                cipher_matrix[i][j] += key_matrix[i][x] * message_vector[x][j]
            cipher_matrix[i][j] %= 26
    return cipher_matrix


def hill_cipher_encrypt(message, key, size):
    key_matrix = get_key_matrix(key, size)
    message_vector = [[ord(char) % 65] for char in message]
    cipher_matrix = encrypt_message(message_vector, key_matrix, size)
    cipher_text = "".join(chr(cipher_matrix[i][0] + 65) for i in range(size))
    return cipher_text


message = input("Enter the message: ").upper()
key = input("Enter the key string: ").upper()
size = int(len(key) ** 0.5)

if len(message) != size:
    print("Error: Message length must match the size of the key matrix.")
else:
    cipher_text = hill_cipher_encrypt(message, key, size)
    print(f"Ciphertext: {cipher_text}")
