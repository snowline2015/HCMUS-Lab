import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn import linear_model

data = pd.read_csv('../wine.csv', sep=';')
dt = data.to_numpy()

def switch_col(argument):
    switcher = {
        0: "fixed acidity",
        1: "volatile acidity",
        2: "citric acid",
        3: "residual sugar",
        4: "chlorides",
        5: "free sulfur dioxide",
        6: "total sulfur dioxide",
        7: "density",
        8: "pH",
        9: "sulphates",
        10: "alcohol",
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

def theta(A, b):
    theta = np.linalg.inv(np.matmul(np.transpose(A), A)) @ np.matmul(np.transpose(A), b)
    return theta

def norm(A, b, theta):
    return np.linalg.norm(A @ theta - b)

def show(xs, ys, theta):
    plt.plot(xs, ys, "o", color="blue")
    ts = np.linspace(min(xs), max(xs), 50)
    yts = [model(t, theta) for t in ts]
    plt.plot(ts, yts, color="red")
    plt.show()


# Cau a
def Cau_a():
    x = (data.loc[:, "fixed acidity":"alcohol"]).to_numpy()
    y = (data.loc[:, ["quality"]]).to_numpy()
    A, b = getAb(x, y)
    print(theta(A, b))
    print(norm(A, b, theta(A, b)))
    #print(model_a(theta(A, b)))


#Cau b
def Cau_b():
    col = None
    temp = None
    y = (data.loc[:, ["quality"]]).to_numpy()
    for i in range(11):
        x = (data.loc[:, [switch_col(i)]]).to_numpy()
        A, b = getAb(x, y)
        if i == 0 or norm(A, b, theta(A, b)) < temp:
            temp = norm(A, b, theta(A, b))
            col = x

    print(col)
    print(temp)
    show(col, y, theta(A, b))


#Cau c
#Sigmoid : ln(y) = theta + theta * x ^ 2 + theta * x^4
def self_getAb(x, y):
    col1 = np.ones(len(x))
    colx = np.transpose(np.array(x))
    A = np.transpose(np.vstack((col1, colx**2, colx**4)))
    b = np.array(y).reshape(len(y), 1)
    return A, b

def self_model(x, theta):
    return np.exp(theta[0] + theta[1] * x ** 2 + theta[1] * x ** 4)

def Cau_c():
    x = (data.loc[:, "fixed acidity":"alcohol"]).to_numpy()
    y = (data.loc[:, ["quality"]]).to_numpy()
    A, b = self_getAb(x, y)
    print(theta(A, b))
    print(norm(A, b, theta(A, b)))


if __name__ == "__main__":
    Cau_b()
