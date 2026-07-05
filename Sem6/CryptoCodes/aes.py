# S-box and Rcon tables (truncated for brevity)
sbox = [
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
]

# Rcon table (truncated)
Rcon = [
    0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8,
    0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3,
    # ... (remaining values from original C code)
]

def substitute_bytes(state):
    # Replace every byte in the state with its S-box value.
    for i in range(4):
        for j in range(4):
            state[i][j] = sbox[state[i][j]]
    return state

def shift_rows(state):
    # Shift each row to the left by a row-dependent offset.
    state[1] = state[1][1:] + state[1][:1]
    state[2] = state[2][2:] + state[2][:2]
    state[3] = state[3][3:] + state[3][:3]
    return state

def xtime(x):
    """Multiply by 2 in GF(2^8)"""
    return ((x << 1) & 0xff) ^ (0x1b if (x & 0x80) else 0x00)

def mix_single_column(col):
    """Mix a single column using the AES MixColumns operation."""
    a = col[:]  # Original column
    b = [0] * 4
    b[0] = xtime(a[0]) ^ (xtime(a[1]) ^ a[1]) ^ a[2] ^ a[3]
    b[1] = a[0] ^ xtime(a[1]) ^ (xtime(a[2]) ^ a[2]) ^ a[3]
    b[2] = a[0] ^ a[1] ^ xtime(a[2]) ^ (xtime(a[3]) ^ a[3])
    b[3] = (xtime(a[0]) ^ a[0]) ^ a[1] ^ a[2] ^ xtime(a[3])
    return b

def mix_columns(state):
    # Mix each column of the state.
    for i in range(4):
        col = [state[0][i], state[1][i], state[2][i], state[3][i]]
        mixed = mix_single_column(col)
        for j in range(4):
            state[j][i] = mixed[j]
    return state

def add_round_key(state, round_key):
    # XOR each byte of the state with the corresponding byte of the round key.
    for i in range(4):
        for j in range(4):
            state[i][j] ^= round_key[i][j]
    return state

def key_expansion(key):
    """
    Expand a 16-byte key into 11 round keys (AES-128).
    Each round key is represented as a 4x4 matrix.
    """
    Nk = 4      # 4 words (16 bytes)
    Nr = 10     # 10 rounds
    Nb = 4      # Block size in words
    w = []      # List to hold words (each is a list of 4 bytes)

    # The first Nk words are simply the key.
    for i in range(Nk):
        w.append(key[4*i: 4*i+4])
    
    # Generate the remaining words.
    for i in range(Nk, Nb*(Nr+1)):
        temp = w[i-1][:]
        if i % Nk == 0:
            # Rotate word left by one.
            temp = temp[1:] + temp[:1]
            # Apply the S-box to each byte.
            temp = [sbox[b] for b in temp]
            # XOR the first byte with the round constant.
            temp[0] ^= Rcon[i//Nk]
        new_word = [ w[i-Nk][j] ^ temp[j] for j in range(4) ]
        w.append(new_word)
    
    # Group words into round keys (each is a 4x4 matrix, column-major).
    round_keys = []
    for r in range(Nr+1):
        round_key = [[0]*4 for _ in range(4)]
        for c in range(4):
            word = w[r*4 + c]
            for r_i in range(4):
                round_key[r_i][c] = word[r_i]
        round_keys.append(round_key)
    return round_keys

def aes_encrypt_block(plaintext, key):
    """
    Encrypt a single 16-byte block (plaintext) with AES-128.
    plaintext: list of 16 integers (bytes)
    key: list of 16 integers (bytes)
    Returns the final state (a 4x4 matrix) which is the ciphertext block.
    """
    round_keys = key_expansion(key)
    
    # Create state matrix (4x4) from plaintext in column-major order.
    state = [[0]*4 for _ in range(4)]
    for i in range(16):
        state[i % 4][i // 4] = plaintext[i]
    
    # Initial round: AddRoundKey.
    state = add_round_key(state, round_keys[0])
    
    # 9 Main Rounds: SubBytes, ShiftRows, MixColumns, AddRoundKey.
    for rnd in range(1, 10):
        state = substitute_bytes(state)
        state = shift_rows(state)
        state = mix_columns(state)
        state = add_round_key(state, round_keys[rnd])
    
    # Final Round (No MixColumns): SubBytes, ShiftRows, AddRoundKey.
    state = substitute_bytes(state)
    state = shift_rows(state)
    state = add_round_key(state, round_keys[10])
    
    return state

def state_to_ciphertext(state):
    """
    Convert the 4x4 state matrix to a 16-byte ciphertext,
    reading the matrix in column-major order.
    """
    ciphertext = []
    for col in range(4):
        for row in range(4):
            ciphertext.append(state[row][col])
    return ciphertext

def print_state(state, label="State"):
    print(label + ":")
    for row in state:
        print(" ".join("{:02X}".format(x) for x in row))
    print()

if __name__ == "__main__":
    # Given plaintext (16 bytes)
    plaintext = [
        0x00, 0x01, 0x02, 0x03,
        0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0A, 0x0B,
        0x0C, 0x0D, 0x0E, 0x0F
    ]


    
    # Given key (16 bytes)
    key = [
        0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01
    ]

    
    # Encrypt the block.
    encrypted_state = aes_encrypt_block(plaintext, key)
    
    # Convert the state matrix to ciphertext bytes.
    ciphertext = state_to_ciphertext(encrypted_state)
    
    print("Plaintext:")
    print(" ".join("{:02X}".format(b) for b in plaintext))
    print("\nKey:")
    print(" ".join("{:02X}".format(b) for b in key))
    
    print("\nFinal Round Key (Round 10):")
    round_keys = key_expansion(key)
    print_state(round_keys[10], label="Round 10 Key")
    
    print("\nEncrypted State (Ciphertext Matrix):")
    print_state(encrypted_state, label="Encrypted State")
    
    print("Ciphertext:")
    print(" ".join("{:02X}".format(b) for b in ciphertext))