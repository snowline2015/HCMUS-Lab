# Võ Hoàng Gia Bảo
# 19127102
# 19CLC9

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

data = pd.read_csv('500_Person_Gender_Height_Weight_Index.csv')
dt = data.to_numpy()


def switch_col(argument):
    switcher = {
        0: "Height",
        1: "Weight",
        2: "Index"
    }
    return switcher.get(argument, "Invalid")


# y = theta_1 + theta_2 * x
def getAb(x, y):
    col1 = np.ones(len(x))
    colx = np.transpose(np.array(x))
    A = np.transpose(np.vstack((col1, colx)))
    b = np.array(y).reshape(len(y), 1)
    return A, b

def model(x, theta):
    return theta[0] + theta[1]*x


# y = theta_1 + theta_2 * x + theta_3 * x^2
def getAb_2(x, y):
    col1 = np.ones(len(x))
    colx = np.transpose(np.array(x))
    A = np.transpose(np.vstack((col1, colx, colx**2)))
    b = np.array(y).reshape(len(y), 1)
    return A, b

def model_2(x, theta):
    return theta[0] + theta[1] * x + theta[1] * x ** 2


def theta(A, b):
    theta = np.linalg.inv(A.T @ A) @ (A.T @ b)
    return theta


def norm(A, b, theta):
    return np.linalg.norm(A @ theta - b)


def show(xs, ys, theta, num):
    plt.plot(xs, ys, "o", color="blue")
    ts = np.linspace(min(xs), max(xs), 50)
    yts = [model(t, theta) if num == 1 else model_2(t, theta) for t in ts]
    plt.plot(ts, yts, color="red")
    plt.show()


if __name__ == "__main__":
    # VD 1
    x = [5, 2, 4, 2]
    y = [2, 2, 1, 1]
    A, b = getAb(x, y)
    print(A, b)
    print(theta(A, b))
    print(norm(A, b, theta(A, b)))
    show(x, y, theta(A, b), 1)

    # VD 2
    x = [2, 1, 5, 3]
    y = [1, 1, 2, 4]
    A, b = getAb_2(x, y)
    print(A, b)
    print(theta(A, b))
    print(norm(A, b, theta(A, b)))
    show(x, y, theta(A, b), 2)

    # # Data file CSV
    col = None
    temp = None
    y = (data.loc[:, ["Index"]]).to_numpy()
    for i in range(2):
        x = (data.loc[:, [switch_col(i)]]).to_numpy()
        A, b = getAb(x, y)
        if i == 0 or norm(A, b, theta(A, b)) < temp:
            temp = norm(A, b, theta(A, b))
            col = x
    print(col)
    print(theta(A, b))
    print(temp)
    show(col, y, theta(A, b), 1)


