#Name- Niyati Kumaria
#Reg No- 22BCE2017

def encrypt(message, shiftkey):
    newmessage = message.replace(" ", "")
    encryptedmsg = ""
    for c in newmessage:
        if c.islower():
            en = (ord(c) + shiftkey - ord('a')) % 26 + ord('a')
            encryptedmsg += chr(en)
        elif c.isupper():
            en = (ord(c) + shiftkey - ord('A')) % 26 + ord('A')
            encryptedmsg += chr(en)
    return encryptedmsg

def decrypt(encryptedmsg, shiftkey):
    decryptedmsg = ""
    for c in encryptedmsg:
        if c.isupper():
            de = (ord(c) - shiftkey - ord('A') + 26) % 26 + ord('A')
            decryptedmsg += chr(de)
        elif c.islower():
            de = (ord(c) - shiftkey - ord('a') + 26) % 26 + ord('a')
            decryptedmsg += chr(de)
    return decryptedmsg


msg = input("Enter a string for encryption using Caesar Cipher: ")
shiftkey = int(input("Enter the shift key: "))

encrypted_data = encrypt(msg, shiftkey)
print("Encrypted Message:", encrypted_data)

decrypted_data = decrypt(encrypted_data, shiftkey)
print("Decrypted Message:", decrypted_data)



