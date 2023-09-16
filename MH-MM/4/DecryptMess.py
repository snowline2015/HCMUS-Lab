# MSSV: 19127102
# Ho ten: Vo Hoang Gia Bao
# MSSV: 19127406
# Ho ten: Ngo Huy Hoang

import base64


def decryption(file_name, pri_key_file_name):
    file_to_decrypt = open(file_name, 'r').read().split(' ')
    pri_key = open(pri_key_file_name, 'r').read().split("\n")
    file = open('decrypted.txt', 'w')
    decrypted = ""

    for i in file_to_decrypt:
        if i:
            c1, c2 = base64.b64decode(i.encode('ascii')).decode('ascii').split(',')

            # for small number only ( < 10**5 characters )
            # m = (pow(int(c1), int(pri_key[0]) - 1 - int(pri_key[1])) * int(c2)) % int(pri_key[0])

            # for large number
            # (A * B) mod C = (A mod C * B mod C) mod C
            m = (pow(int(c1),int(pri_key[0]) - 1 - int(pri_key[1]),int(pri_key[0])) * int(c2) % int(pri_key[0])) % int(pri_key[0])

            decrypted += chr(m)

    file.write(decrypted)
    file.close()


# Cau 3
decrypt_file_name = input("Input file name to decrypt: ")
pri_key_file_name = input("Input private key file name to decrypt: ")
decryption(decrypt_file_name, pri_key_file_name)
