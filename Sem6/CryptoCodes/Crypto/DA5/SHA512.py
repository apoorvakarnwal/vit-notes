#Name- Niyati Kumaria
#Reg No- 22BCE2017

def preprocess_message(message):
    if isinstance(message, str):
        binary = ''.join(format(ord(char), '08b') for char in message)
    else:
        binary = ''.join(format(byte, '08b') for byte in message)
    
    original_length = len(binary)
    
    binary += '1'
    
    padding_length = (896 - (len(binary) % 1024)) % 1024
    binary += '0' * padding_length
    
    binary += format(original_length, '0128b')
    
    blocks = [binary[i:i+1024] for i in range(0, len(binary), 1024)]
    
    return blocks

def generate_message_schedule(block):
    words = [int(block[i:i+64], 2) for i in range(0, 1024, 64)]
    
    W = [0] * 80
    W[:16] = words
    
    for t in range(16, 80):
        s0 = (right_rotate(W[t-15], 1) ^ right_rotate(W[t-15], 8) ^ (W[t-15] >> 7))
        s1 = (right_rotate(W[t-2], 19) ^ right_rotate(W[t-2], 61) ^ (W[t-2] >> 6))
        W[t] = (W[t-16] + s0 + W[t-7] + s1) & 0xFFFFFFFFFFFFFFFF
    
    return W

def right_rotate(value, shift):
    return ((value >> shift) | (value << (64 - shift))) & 0xFFFFFFFFFFFFFFFF

def main():
    message = input("Enter message to hash: ")
    
    blocks = preprocess_message(message)
    print(f"\nNumber of 1024-bit blocks: {len(blocks)}")
    
    for i, block in enumerate(blocks, 1):
        print(f"\nProcessing Block {i}:")
        
        W = generate_message_schedule(block)
        
        print("\nFirst 16 words (original message block):")
        for j in range(16):
            print(f"W[{j:2d}]: {W[j]:016x}")
        
        print("\nSample expanded words (17-20, 40-43, 76-79):")
        for j in range(16, 20):
            print(f"W[{j:2d}]: {W[j]:016x}")
        for j in range(40, 44):
            print(f"W[{j:2d}]: {W[j]:016x}")
        for j in range(76, 80):
            print(f"W[{j:2d}]: {W[j]:016x}")

if __name__ == "__main__":
    main()