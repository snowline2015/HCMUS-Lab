import numpy as np
import copy

# Ham tao ma tran con tu phan bu dai so
def sub_matrix(A, removed_row, removed_col):
    sub_A = copy.deepcopy(A)

    # Bo dong
    sub_A = np.delete(sub_A, removed_row, 0)

    # Bo cot
    sub_A = np.delete(sub_A, removed_col, 1)

    return sub_A

# Ham tinh dinh thuc ma tran
def determinant(A):
    # 1x1
    if len(A) == len(A[0]) == 1:
        return A[0][0]

    # 2x2
    if len(A) == len(A[0]) == 2:
        return A[0][0] * A[1][1] - A[1][0] * A[0][1]

    # else
    total = 0
    for removed_col in range(len(A[0])):
        # Lay dong 1 roi lap tat ca cac cot
        sub_A = sub_matrix(A, 0, removed_col)

        sign = (-1) ** (1 + (removed_col + 1))

        # Tim dinh thuc con bang de quy
        sub_det = determinant(sub_A)

        # Cong cac dinh thuc con
        total += A[0][removed_col] * sign * sub_det

    return total

def multiply_number_to_matrix(num, A):
    return [[num * a for a in row] for row in A]

# Ham tinh ma tran nghich dao
def inverse(A):
    det = determinant(A)
    if det == 0:
        print(" Ma tran khong kha nghich ")
        return None

    # 1x1
    if len(A) == len(A[0]) == 1:
        return 1/det

    # Tao ma tran bo sung
    row = len(A)
    col = len(A[0])
    B = np.zeros((row, col))

    # Tao ma tran chuyen vi tu ma tran goc
    A_trans = np.transpose(A)

    for i in range(row):
        for j in range(col):
            # Tao cac ma tran phan bu dai so
            sub_A = sub_matrix(A_trans, i, j)

            # Tim dau
            sign = (-1) ** (i + j)
            B[i][j] = sign * determinant(sub_A)

    # Chia ma tran bo sung voi dinh thuc cua ma tran
    B = multiply_number_to_matrix(1/det, B)

    # In ra gia tri lam tron 5 chu so thap phan, tra ve ma tran nghich dao
    print(np.round(B, 5))
    return B

"""
if __name__ == '__main__':
    A = ([1,2,3],
         [2,5,3],
         [1,0,8])

    inverse(A)
"""