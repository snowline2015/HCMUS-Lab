# Ho ten: Vo Hoang Gia Bao
# MSSV: 19127102
# Lop: 19CLC9

import random as rd

# Tao ma tran xac suat chuyen trang thai ngau nhien
# Input:
# n: kich thuoc ma tran
# Output: ma tran xac suat chuyen trang thai ngau nhien
def Cau_1():
    print("Nhap kich thuoc n:")
    n = int(input())
    A = []
    for i in range(n):
        row = []
        sum_ = 1
        j = 0
        while (j < n):
            if j == n - 1:
                row.append(sum_)
                break
            temp = rd.random()
            sum_ -= temp
            if (sum_ < 0):              # Random lai so truoc do neu tong dong > 1
                j -= 1
                sum_ += temp
            else:
                row.append(temp)
            j += 1
        A.append(row)
    return A


# Nhan 2 ma tran
#input: ma tran A, ma tran B
#output: ma tran moi da nhan
def multiply_matrix(A, B):
    result = [[0 for _ in range(len(B[0]))] for _ in range(len(A))]
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                result[i][j] += A[i][k] * B[k][j]
    return result

# Tao vecto pi zero va in ra pi 1, pi 2, pi 3
# Input:
# A: ma tran xac suat chuyen trang thai
# Output: pi_1,pi_2,pi_3
def Cau_2(A):
    # Tao vecto pi zero
    pi_zero = [0] * len(A[0]);
    for i in range(1):
        pi_zero[rd.randint(0, 1) % len(A[0])] += 1;
    pi_zero = [pi_zero]

    #pi 1
    pi_1 = multiply_matrix(A, pi_zero)

    # pi 2
    pi_2 = multiply_matrix(multiply_matrix(A, A), pi_zero)

    # pi 3
    pi_3 = multiply_matrix(multiply_matrix(multiply_matrix(A, A), A), pi_zero)

    return pi_1, pi_2, pi_3

if __name__ == "__main__":
    A = Cau_1()
    print(A)
    print(Cau_2(A))