# Fibonacci Sequence (Harder)


class Mat:
    def __init__(self, mat):
        self.mat = mat

    def __mul__(self, other):
        MOD = int(1e9) + 7
        a = ((self.mat[0][0] * other.mat[0][0]) % MOD + (self.mat[0][1] * other.mat[1][0]) % MOD) % MOD
        b = ((self.mat[0][0] * other.mat[0][1]) % MOD + (self.mat[0][1] * other.mat[1][1]) % MOD) % MOD
        c = ((self.mat[1][0] * other.mat[0][0]) % MOD + (self.mat[1][1] * other.mat[1][0]) % MOD) % MOD
        d = ((self.mat[1][0] * other.mat[0][1]) % MOD + (self.mat[1][1] * other.mat[1][1]) % MOD) % MOD
        return Mat([[a, b], [c, d]])


def qpow(mat, exp):
    ret = Mat([[1, 0], [0, 1]])
    while exp > 0:
        if exp & 1:
            ret *= mat
        mat *= mat
        exp >>= 1
    return ret


a = Mat([[1, 1], [1, 0]])
print(qpow(a, int(input())).mat[0][1])
