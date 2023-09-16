# Võ Hoàng Gia Bảo
# 19127102
# 19CLC9

import sympy as sp
import numpy as np
import math
from math import sqrt
from copy import deepcopy


def multiply_number_vector(number, A_list):
    Copy = deepcopy(A_list).astype('float')
    for i in range(len(A_list)):
        Copy[i] *= number
    return Copy


def norm_vector(vector):
    sum = 0
    for i in range(len(vector)):
        sum += vector[i] ** 2
    return math.sqrt(sum)


def qr_decomposition(A):
    # Bước 1: Đặt các vector 𝑢_𝑖 lần lượt từng cột i của ma trận A
    u = [None for _ in range(len(A[0]))]
    for i in range(len(A[0])):
        u[i] = np.array(A)[:,i]

    # Bước 2: Tìm họ trực giao 𝑣_𝑖 của các vector 𝑢_𝑖
    v = [None for _ in range(len(A[0]))]
    for i in range(len(A[0])):
        v[i] = u[i]

        if norm_vector(v[i]) == 0:
            print('Ho khong doc lap tuyen tinh\n')
            return None

        if i != 0:
            for j in range(i):      # trừ dần
                v[i] = np.subtract(v[i], (multiply_number_vector(u[i] @ v[j] / norm_vector(v[j]) ** 2, v[j])))

    q = [None for _ in range(len(A[0]))]
    Q = [None for _ in range(len(A[0]))]
    R = np.zeros((len(A), len(A[0])), dtype=float)

    # Bước 3: Tính trực chuẩn 𝑞_𝑖 của các vector trực giao 𝑣_𝑖
    for i in range(len(A[0])):
        q[i] = np.around(multiply_number_vector(1.0 / norm_vector(v[i]), v[i]), 3)
        Q = np.vstack((Q, q[i]))        # Bước 4: Gộp ma trận Q
    Q = (np.delete(Q, 0, 0)).T

    # Bước 5: Ta có A = QR  R = Q^-1A. Tính R
    for i in range(len(A)):
        for j in range(i, len(A[0])):
            R[i][j] = q[i] @ u[j]
    print(Q, '\n\n', R, '\n\n')

    # So sánh hàm tự làm với hàm numpy
    Q_np, R_np = np.linalg.qr(A)
    print(Q_np, '\n\n', sp.Matrix(R_np))

    return Q_np, R_np


def diagonalize_matrix(A):
    M = sp.Matrix(A)

    # Kiểm tra ma trận có chéo hóa được không
    if M.is_diagonalizable() == False:
        print('Matrix is not diagonalizable\n')
        return

    # Trả về 2 ma trận chéo hóa P và ma trận chéo D
    P, D = M.diagonalize()

    PDP1 = P * D * P.inv()

    A_np = np.around(np.array(A).astype(np.float_), 3)
    temp = eval(str(PDP1)[6:])              # Rút gọn các biểu thức trong matrix của sympy
    temp = np.around(np.array(temp), 3)     # Làm tròn

    # So sánh A == PDP^-1 lần cuối dù chắc chắn sẽ bằng nhau
    if np.array_equal(temp, A_np):
        print(np.around(np.array(eval(str(P)[6:])), 3), '\n*\n', np.around(np.array(eval(str(D)[6:])), 3), '\n*\n',
              temp, '\n=\n', sp.Matrix(A))

    return P, D


if __name__ == '__main__':
    A = ([2,1,1],
         [2,1,2],
         [1,1,2])
    qr_decomposition(A)

    B = ([2,-1,2],
         [0,2,3],
         [-1,1,-1])
    diagonalize_matrix(B)
