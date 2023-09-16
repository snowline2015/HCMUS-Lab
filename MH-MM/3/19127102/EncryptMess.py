# MSSV: 19127102
# Ho ten: Vo Hoang Gia Bao

import base64


def encryption(file_name, pub_key_file_name):
    file_to_encrypt = open(file_name, 'r').read()
    pub_key = open(pub_key_file_name, 'r').read().split("\n")
    file = open('encrypted.txt', 'w')
    encrypted = ""

    for char in file_to_encrypt:
        m = ord(char)
        temp = str(pow(m, int(pub_key[0]), int(pub_key[1])))
        encrypted += base64.b64encode(temp.encode('ascii')).decode('ascii') + ' '

    file.write(encrypted)
    file.close()


# Cau 2
encrypt_file_name = input("Input file name to encrypt: ")
pub_key_file_name = input("Input public key file name to encrypt: ")
encryption(encrypt_file_name, pub_key_file_name)
