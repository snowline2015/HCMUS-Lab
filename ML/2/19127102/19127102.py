# MSSV: 19127102
# Ho ten: Vo Hoang Gia Bao

from map_feature import map_feature
import json
import pandas as pd
import numpy as np
from copy import deepcopy
import seaborn as sns
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


def sigmoid_func(z):
    return 1/(1 + np.exp(-z))


class LogisticRegression:
    def __init__(self, alpha, iters, lamda):
        self.alpha = alpha
        self.iters = iters
        self.lamda = lamda
        self.theta = None

    def compute_cost(self, X, y, theta):
        m = len(y)
        h_theta = sigmoid_func(np.dot(X, theta))
        cost = (1.0 / m) * np.sum((-y * np.log(h_theta) - (1 - y) * np.log(1 - h_theta))) + \
               (self.lamda / (2 * m)) * np.sum((theta ** 2))
        return cost

    def compute_gradient(self, X, y, theta):
        m = len(y)

        h_theta = sigmoid_func(np.dot(X, theta))
        loss = h_theta - y

        dJ = np.zeros(theta.shape)
        for i in range(len(dJ)):
            dJ[i] = (1 / m) * np.sum(np.dot(loss.T, np.array(X[:, i]).reshape(m, 1)))
            if i >= 1:
                dJ[i] += (self.lamda / m) * theta[i]

        J = self.compute_cost(X, y, theta)
        return (J, dJ)

    def gradient_descent(self, X, y):
        theta = np.zeros((X.shape[1], 1))
        for i in range(self.iters):
            J, dJ = self.compute_gradient(X, y, theta)
            theta = theta - self.alpha * dJ
        return theta

    def fit(self, X, y):
        self.theta = self.gradient_descent(X, y)

    def predict(self, X):
        temp = map_feature(X[:,0], X[:,1])
        pred = sigmoid_func(np.dot(temp, model.theta))
        results = [[1] if i >= 0.5 else [0] for i in pred]
        return results


# Main function
# Read training config
with open('config.json',) as f:
    configs = json.load(f)

# Read training dataset
file_path = 'training_data.txt'
df = pd.read_csv(file_path, sep=",", header=None)

X = (df.loc[:, 0:1]).to_numpy()
y = df.iloc[:, -1:].values

# Feature mapping
X = map_feature(X[:,0], X[:,1])

model = LogisticRegression(configs["Alpha"], configs["NumIter"], configs["Lambda"])
model.fit(X, y)

# Predict training dataset
new_X = (df.loc[:, 0:1]).to_numpy()
pred = model.predict(new_X)

# Calculate accuracy of training data set
accuracy = 0
for i in range(len(pred)):
    if pred[i] == y[i]: accuracy += 1
accuracy = accuracy / len(pred) * 100

# Save model
with open('model.json', 'w') as f:
    json.dump({'theta: ': model.theta.tolist()}, f)

# Save results
with open('accuracy.json', 'w') as f:
    json.dump({'accuracy: ': round(accuracy, 3)}, f)

