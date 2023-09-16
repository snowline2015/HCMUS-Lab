# MSSV: 19127102
# Ho ten: Vo Hoang Gia Bao
# MSSV: 19127406
# Ho ten: Ngo Huy Hoang

import random


# Source: https://rosettacode.org/wiki/Miller%E2%80%93Rabin_primality_test#Python
def is_prime(n):
    """
    Miller-Rabin primality test.

    A return value of False means n is certainly not prime. A return value of
    True means n is very likely a prime.
    """
    if n != int(n):
        return False
    n = int(n)
    # Miller-Rabin test for prime
    if n == 0 or n == 1 or n == 4 or n == 6 or n == 8 or n == 9:
        return False
    if n == 2 or n == 3 or n == 5 or n == 7:
        return True
    s = 0
    d = n - 1
    while d % 2 == 0:
        d >>= 1
        s += 1
    assert (2 ** s * d == n - 1)

    def trial_composite(a):
        if pow(a, d, n) == 1:
            return False
        for i in range(s):
            if pow(a, 2 ** i * d, n) == n - 1:
                return False
        return True

    for i in range(8):  # number of trials
        a = random.randrange(2, n)
        if trial_composite(a):
            return False

    return True


def large_prime_generator(length=10):       # Ex: 128 -> 1024 bits
    while True:
        temp = random.randint(0, 10 ** length)
        if is_prime(temp):
            return temp


def Elgamal_key_generation():
    p = large_prime_generator()
    alpha = random.randrange(1, p)  # if |G| is prime, then all elements a not 1 \in G are primitives
    d = random.randrange(2, p - 1)  # from 2 to p-2
    beta = pow(alpha, d, p)

    pub_key = (p,alpha,beta)
    pri_key = (p,d)
    return pub_key, pri_key


# Cau 1
path = input("Input path to store keys: ")
pub_key, pri_key = Elgamal_key_generation()

file = open(path + "\\el_pub.txt", "w")
file.write("{0}\n{1}\n{2}".format(pub_key[0], pub_key[1], pub_key[2]))

file = open(path + "\\el.txt", "w")
file.write("{0}\n{1}".format(pri_key[0], pri_key[1]))
file.close()






