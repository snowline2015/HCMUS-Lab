# MSSV: 19127102
# Ho ten: Vo Hoang Gia Bao

import base64


def decryption(file_name, pri_key_file_name):
    file_to_decrypt = open(file_name, 'r').read().split(' ')
    pri_key = open(pri_key_file_name, 'r').read().split("\n")
    file = open('decrypted.txt', 'w')
    decrypted = ""

    for i in file_to_decrypt:
        if i:
            temp = base64.b64decode(i.encode('ascii')).decode('ascii')
            decrypted += chr(pow(int(temp), int(pri_key[0]), int(pri_key[1])))

    file.write(decrypted)
    file.close()


# Cau 3
decrypt_file_name = input("Input file name to decrypt: ")
pri_key_file_name = input("Input private key file name to decrypt: ")
decryption(decrypt_file_name, pri_key_file_name)
