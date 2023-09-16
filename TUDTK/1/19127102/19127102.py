import numpy as np
import string


def Gauss_elimination(A):
    rows = len(A)
    cols = len(A[0])

    # Hoan doi 2 dong de de tinh toan
    if A[0][0] == 0:
        for i in range(rows):
            if A[i][0] != 0:
                temp = A[0]
                A[0] = A[i]
                A[i] = temp
                break

    for i in range(rows):
        flag = False
        if A[i][i] == 0:
            # kiem tra cac dong tren 1 cot tren duong cheo neu != 0 thi hoan doi 2 dong
            for j in range(i + 1, rows):
                if A[j][i] != 0:
                    temp = A[j]
                    A[j] = A[i]
                    A[i] = temp
                    flag = True
                    break

            # Kiem tra neu khong hoan doi dc thi kiem tra cac he so tren 1 dong != 0
            if flag == False:
                for j in range(i + 1, cols):
                    if A[i][j] != 0:
                        for k in range(i + 1, rows):
                            ratio = - (A[k][j] / A[i][j])
                            for l in range(cols):
                                A[k][l] = A[k][l] + ratio * A[i][l]

        # Neu he so tren duong cheo != 0 thi thuc hien binh thuong
        if A[i][i] != 0:
            for j in range(i + 1, rows):
                ratio = - (A[j][i] / A[i][i])
                for k in range(cols):
                    A[j][k] = A[j][k] + ratio * A[i][k]
    return A


def back_substitution(A):
    rows = len(A)
    cols = len(A[0])

    # Truong hop vo nghiem
    for i in reversed(range(rows)):
        if A[i][0] == 0:
            for j in range(1, cols):
                if j != cols - 1 and A[i][j] != 0:
                    break
                if j == cols - 1 and A[i][j] != 0:
                    print("He phuong trinh vo nghiem\n")
                    return None

    # Kiem tra hang
    B = [None] * (cols - 1)
    rank = np.linalg.matrix_rank(A)
    unknownSol = cols - 1 - rank

    # Truong hop vo so nghiem
    if unknownSol > 0:
        alphabet_list = list(string.ascii_uppercase)
        alphabet_count = 0

        # Chuyen cac nghiem an -> cac chu cai A, B, C,...
        temp = unknownSol
        for i in range(rank):
            if A[i][i] == 0:
                B[i] = alphabet_list[alphabet_count]
                temp -= 1
                alphabet_count += 1
        if temp > 0:
            for i in reversed(range(len(B))):
                if temp == 0:
                    break
                B[i] = alphabet_list[alphabet_count]
                temp -= 1
                alphabet_count += 1

        # Thuc hien phep tinh
        reverse_count = len(B) - 1
        for i in reversed(range(rank)):
            flag = False
            for j in reversed(range(cols)):
                if flag == False:
                    while B[reverse_count] != None:
                        if reverse_count == 0:
                            print(B)
                            return B
                        reverse_count -= 1
                    flag = True

                if j == reverse_count and B[reverse_count] != None:
                    break

                if B[reverse_count] == None:
                    B[reverse_count] = str(round(A[i][j] / A[i][reverse_count], 3))

                else:
                    B[reverse_count] += " + " + str(round(-A[i][j] / A[i][reverse_count], 3)) + " * (" + str(B[j]) + ")"

        print(B)
        return B

    # Truong hop co nghiem duy nhat
    else:
        for i in reversed(range(len(B))):
            for j in reversed(range(cols)):
                if i == j:
                    B[i] /= A[i][i]
                    break
                if B[i] == None:
                    B[i] = A[i][j]
                else:
                    B[i] -= A[i][j] * B[j]
        np.round(B, 3)
        print(B)
        return B


"""
def main():

    A = ([4,-2,-4,2,1],
         [6,-3,0,-5,3],
         [8,-4,28,-44,11],
         [-8,4,-4,12,-5])

    Gauss_elimination(A)
    back_substitution(A)


if __name__ == "__main__":
    main()
"""






