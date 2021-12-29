# Rotations in 3 Dimensions

from math import sqrt, sin, cos


class Mat:
    def __init__(self, arr):
        self.arr = arr

    def __mul__(self, other):
        ret = [[0 for i in range(len(other.arr[0]))] for j in range(len(self.arr))]
        for i in range(len(self.arr)):
            for j in range(len(other.arr[0])):
                for k in range(len(self.arr[0])):
                    ret[i][j] += self.arr[i][k] * other.arr[k][j]
        return Mat(ret)


def rotate2d(x, y, theta):
    # rotate theta degrees around the origin in 2D
    nx = cos(theta) * x - sin(theta) * y
    ny = sin(theta) * x + cos(theta) * y
    return nx, ny


def rotate3d(x, y, z, px, py, pz, theta):
    # rotate point (x, y, z)
    # theta degrees around vector formed by
    # (0, 0, 0) and (px, py, pz)
    A = px
    B = py
    C = pz

    if B == 0 and C == 0:
        return x, *rotate2d(y, z, theta)

    L = sqrt(A ** 2 + B ** 2 + C ** 2)
    V = sqrt(B ** 2 + C ** 2)

    D = Mat([[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]])
    Rx = Mat([[1, 0, 0, 0], [0, C / V, -B / V, 0], [0, B / V, C / V, 0], [0, 0, 0, 1]])
    Ry = Mat([[V / L, 0, -A / L, 0], [0, 1, 0, 0], [A / L, 0, V / L, 0], [0, 0, 0, 1]])
    Rz = Mat(
        [
            [cos(theta), -sin(theta), 0, 0],
            [sin(theta), cos(theta), 0, 0],
            [0, 0, 1, 0],
            [0, 0, 0, 1],
        ]
    )
    D_inv = Mat([[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]])
    Rx_inv = Mat(
        [[1, 0, 0, 0], [0, C / V, B / V, 0], [0, -B / V, C / V, 0], [0, 0, 0, 1]]
    )
    Ry_inv = Mat(
        [[V / L, 0, A / L, 0], [0, 1, 0, 0], [-A / L, 0, V / L, 0], [0, 0, 0, 1]]
    )

    point = Mat([[x], [y], [z], [1]])
    rotated = D_inv * Rx_inv * Ry_inv * Rz * Ry * Rx * D * point
    rx, ry, rz = map(lambda x: x[0], rotated.arr[:3])
    return rx, ry, rz


for i in range(int(input())):
    x, y, z = rotate3d(*map(float, input().split()))
    print(x, y, z)
