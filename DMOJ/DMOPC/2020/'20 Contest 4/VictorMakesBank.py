# DMOPC '20 Contest 1 P4 - Victor Makes Bank


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


def qpow(mat, exp):
    ret = mat
    exp -= 1
    while exp > 0:
        if exp & 1:
            ret = ret * mat
        mat = mat * mat
        exp //= 2
    return ret


n, k, t, c = map(int, input().split())
MOD = int(1e9) + 7

a = [[0 for i in range(t + 1)] for i in range(t + 1)]
a[0][-1] = k
a[-1][-1] = 1
for i in range(t):
    a[i + 1][i] = 1
a = Mat(a)

other = [[0] for i in range(t + 1)]
other[-1][0] = c

ans = qpow(a, n - 1) * Mat(other)
adult = ans.arr[-1][0] % MOD
child = (sum(x[0] % MOD for x in ans.arr) - adult) % MOD

print((adult * 2 + child) % MOD)
