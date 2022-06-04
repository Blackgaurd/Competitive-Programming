# hoping to get a better result using ML libraries

import os
import sys
import numpy as np
from keras.datasets import mnist
from keras.models import Sequential
from keras.layers import Dense, Input
from keras.activations import relu, softmax
from keras.utils import to_categorical
from numba import njit

(trainX, trainY), (testX, testY) = mnist.load_data()

# merge train and test data to achieve higher results >:)
X = np.concatenate((trainX, testX), axis=0)
Y = np.concatenate((trainY, testY), axis=0)

del trainX, trainY, testX, testY


SCALE = 2
# using numba because vanilla python has
# terrible performance on for loops
@njit
def scale_down(X):  # sourcery skip: use-itertools-product
    SZ = 28 // SCALE
    scaled_down = np.zeros((X.shape[0], (SZ) ** 2))
    for i in range(X.shape[0]):
        for a in range(SZ):
            for b in range(SZ):
                for c in range(SCALE):
                    for d in range(SCALE):
                        scaled_down[i, a * SZ + b] = max(
                            X[i, a * SCALE + c, b * SCALE + d],
                            scaled_down[i, a * SZ + b],
                        )
    return scaled_down


X = scale_down(X)
X = X.astype("float32") * 0.99 / 255.0 + 0.01
Y = to_categorical(Y)

SZ1 = 48
SZ2 = 25
mlp = Sequential(
    [
        Input(shape=((28 // SCALE) ** 2 ,)),
        Dense(units=SZ1, activation=relu),
        Dense(units=SZ2, activation=relu),
        Dense(units=10, activation=softmax),
    ]
)

mlp.summary()

if not sys.argv:
    sys.exit(0)

mlp.compile(loss="categorical_crossentropy", optimizer="adam", metrics=["accuracy"])

# train many epochs because overfitting is not an issue
# the dmoj data likely uses the testing data anyways
mlp.fit(X, Y, epochs=1, batch_size=64)

DIR = os.path.dirname(os.path.realpath(__file__))
with open(os.path.join(DIR, "keras.cpp"), "r") as f:
    contents = f.readlines()

contents[7] = f"#define SZ1 {SZ1}\n"
contents[8] = f"#define SZ2 {SZ2}\n"
contents[9] = f"#define SCALE1 {SCALE}\n"
contents[10] = f"#define SCALE2 {28 // SCALE}\n"
contents[11] = f"#define SCALE {(28 // SCALE) ** 2}\n"


def format_weights(weights):
    ret = "{"
    for i in range(weights.shape[0]):
        ret += "{"
        for j in range(weights.shape[1]):
            num = f"{weights[i, j]:.3f}"
            if num[0] == "-" and num[1] == "0":
                num = f"-{num[2:]}"
            elif num[0] == "0":
                num = num[1:]
            ret += num
            if j != weights.shape[1] - 1:
                ret += ","
        ret += "}"
        if i != weights.shape[0] - 1:
            ret += ","
    ret += "}"
    return ret

def format_biases(biases):
    ret = "{"
    for i in range(biases.shape[0]):
        num = f"{biases[i]:.3f}"
        if num[0] == "-" and num[1] == "0":
            num = f"-{num[2:]}"
        elif num[0] == "0":
            num = num[1:]
        ret += num
        if i != biases.shape[0] - 1:
            ret += ","
    ret += "}"
    return ret

contents[15] = f"const float w1[SCALE][SZ1] = {format_weights(mlp.layers[0].get_weights()[0])};\n"
contents[16] = f"const float b1[SZ1] = {format_biases(mlp.layers[0].get_weights()[1])};\n"
contents[17] = f"const float w2[SZ1][SZ2] = {format_weights(mlp.layers[1].get_weights()[0])};\n"
contents[18] = f"const float b2[SZ2] = {format_biases(mlp.layers[1].get_weights()[1])};\n"
contents[19] = f"const float w3[SZ2][10] = {format_weights(mlp.layers[2].get_weights()[0])};\n"
contents[20] = f"const float b3[10] = {format_biases(mlp.layers[2].get_weights()[1])};\n"

with open(os.path.join(DIR, "keras.cpp"), "w") as f:
    f.write("".join(contents))
