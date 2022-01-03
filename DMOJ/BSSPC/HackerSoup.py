# BSSPC '21 S2 - Hacker Soup
# submit in pypy3

n, k, q = map(int, input().split())


class Square:
    def __init__(self, t, l, b, r):
        self.tl = (t, l)
        self.br = (b, r)
        self.mid = ((t + b) / 2, (l + r) / 2)

    def contains(self, x, y):
        return self.tl[0] <= x <= self.br[0] and self.tl[1] <= y <= self.br[1]

    def rotate(self, x, y):
        x -= self.mid[0]
        y -= self.mid[1]
        x, y = -y, x
        return int(x + self.mid[0]), int(y + self.mid[1])


rotate = [Square(*map(int, input().split())) for i in range(k)]
rotate.reverse()

for i in range(q):
    a, b = map(int, input().split())
    for square in rotate:
        if square.contains(a, b):
            a, b = square.rotate(a, b)
    print((a - 1) * n + b)
