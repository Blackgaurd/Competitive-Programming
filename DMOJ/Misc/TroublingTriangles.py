# Troubling Triangles

from math import sqrt


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def dis(self, other):
        return sqrt((self.x - other.x) ** 2 + (self.y - other.y) ** 2)


for i in range(int(input())):
    x1, y1, x2, y2, x3, y3 = map(int, input().split())
    a, b, c = Point(x1, y1), Point(x2, y2), Point(x3, y3)
    ab = a.dis(b)
    ac = a.dis(c)
    bc = b.dis(c)

    p = ab + ac + bc
    s = p / 2
    a = sqrt(s * (s - ab) * (s - ac) * (s - bc))

    print(a, p)
