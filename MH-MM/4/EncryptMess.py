# MSSV: 19127102
# Ho ten: Vo Hoang Gia Bao
# MSSV: 19127406
# Ho ten: Ngo Huy Hoang

import base64
import random


def encryption(file_name, pub_key_file_name):
    file_to_encrypt = open(file_name, 'r').read()
    pub_key = open(pub_key_file_name, 'r').read().split("\n")
    file = open('encrypted.txt', 'w')
    encrypted = ""

    for char in file_to_encrypt:
        m = ord(char)

        k = random.randint(1, int(pub_key[0]) - 2)
        c1 = pow(int(pub_key[1]), k, int(pub_key[0]))
        c2 = m * pow(int(pub_key[2]), k, int(pub_key[0]))

        temp = str(c1) + ',' + str(c2)
        encrypted += base64.b64encode(temp.encode('ascii')).decode('ascii') + ' '

    file.write(encrypted)
    file.close()


# Cau 2
encrypt_file_name = input("Input file name to encrypt: ")
pub_key_file_name = input("Input public key file name to encrypt: ")
encryption(encrypt_file_name, pub_key_file_name)
