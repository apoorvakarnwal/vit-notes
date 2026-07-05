def text_to_state(text):
    state = [[0 for _ in range(4)] for _ in range(4)]
    for i in range(4):
        for j in range(4):
            state[j][i] = ord(text[i * 4 + j])
    return state

def state_to_text(state):
    text = ""
    for i in range(4):
        for j in range(4):
            text += chr(state[j][i])
    return text

def create_sbox():
    sbox = [[0 for _ in range(16)] for _ in range(16)]
    for i in range(16):
        for j in range(16):
            sbox[i][j] = (i * j) % 256
    return sbox

def sub_bytes(state, sbox):
    for i in range(4):
        for j in range(4):
            byte = state[i][j]
            row = byte >> 4
            col = byte & 0x0F
            state[i][j] = sbox[row][col]
    return state

def shift_rows(state):
    state[1] = state[1][1:] + state[1][:1]
    state[2] = state[2][2:] + state[2][:2]
    state[3] = state[3][3:] + state[3][:3]
    return state

def xtime(x):
    return ((x << 1) & 0xff) ^ (0x1b if (x & 0x80) else 0x00)

def mix_single_column(col):
    a = col[:]  
    b = [0] * 4
    b[0] = xtime(a[0]) ^ (xtime(a[1]) ^ a[1]) ^ a[2] ^ a[3]
    b[1] = a[0] ^ xtime(a[1]) ^ (xtime(a[2]) ^ a[2]) ^ a[3]
    b[2] = a[0] ^ a[1] ^ xtime(a[2]) ^ (xtime(a[3]) ^ a[3])
    b[3] = (xtime(a[0]) ^ a[0]) ^ a[1] ^ a[2] ^ xtime(a[3])
    return b

def mix_columns(state):
    for i in range(4):
        col = [state[0][i], state[1][i], state[2][i], state[3][i]]
        mixed = mix_single_column(col)
        for j in range(4):
            state[j][i] = mixed[j]
    return state

def add_round_key(state, round_key):
    for i in range(4):
        for j in range(4):
            state[i][j] ^= round_key[i][j]
    return state

def key_to_state(key_words, round_num):
    start_idx = round_num * 4
    key_state = [[0 for _ in range(4)] for _ in range(4)]

    for i in range(4):
        word = key_words[start_idx + i]
        for j in range(4):
            key_state[j][i] = word[j]
    
    return key_state

def create_dummy_expanded_key():
    expanded_key = []
    for i in range(44):
        expanded_key.append([i*4 % 256, (i* 4 + 1) % 256, (i * 4 + 2) % 256, (i * 4 + 3) % 256])
    return expanded_key

plaintext = "AESisablockciphe"
expanded_key = create_dummy_expanded_key()
sbox = create_sbox()

state = text_to_state(plaintext)

print("\nInitial State:")
for row in state:
    print(row)

round_key = key_to_state(expanded_key, 0)
state = add_round_key(state, round_key)
print("\nAfter Round 0 (AddRoundKey):")
for row in state:
    print(row)

for round_num in range(1, 10):
    print(f"\n--- Round {round_num} ---")

    state = sub_bytes(state, sbox)
    print("After SubBytes:", *state, sep="\n")

    state = shift_rows(state)
    print("After ShiftRows:", *state, sep="\n")

    state = mix_columns(state)
    print("After MixColumns:", *state, sep="\n")

    round_key = key_to_state(expanded_key, round_num)
    state = add_round_key(state, round_key)
    print("After AddRoundKey:", *state, sep="\n")

print("\n--- Final Round (10) ---")
state = sub_bytes(state, sbox)
state = shift_rows(state)
round_key = key_to_state(expanded_key, 10)
state = add_round_key(state, round_key)

print("After AddRoundKey:", *state, sep="\n")

ciphertext = state_to_text(state)
print("\nFinal Ciphertext:", ciphertext)