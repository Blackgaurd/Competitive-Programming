# CCC '01 S4 - Cookies

from math import sqrt
from itertools import combinations as comb


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    @staticmethod
    def midpoint(p1, p2):
        return Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2)

    @staticmethod
    def dis(p1, p2):
        return sqrt((p1.x - p2.x) ** 2 + (p1.y - p2.y) ** 2)


class Circle(Point):
    def __init__(self, x, y, r):
        super().__init__(x, y)
        self.r = r

    @classmethod
    def line(cls, p1, p2):
        mid = Point.midpoint(p1, p2)
        r = Point.dis(mid, p1)
        return cls(mid.x, mid.y, r)

    @classmethod
    def circumcenter(cls, p1, p2, p3):
        a = p2.y - p3.y
        b = p3.y - p1.y
        c = p1.y - p2.y
        d = 2 * (p1.x * a + p2.x * b + p3.x * c)
        mx = (
            (p1.x ** 2 + p1.y ** 2) * a
            + (p2.x ** 2 + p2.y ** 2) * b
            + (p3.x ** 2 + p3.y ** 2) * c
        ) / d
        my = (
            (p1.x ** 2 + p1.y ** 2) * (p3.x - p2.x)
            + (p2.x ** 2 + p2.y ** 2) * (p1.x - p3.x)
            + (p3.x ** 2 + p3.y ** 2) * (p2.x - p1.x)
        ) / d
        r = Point.dis(Point(mx, my), p1)
        return cls(mx, my, r)

    def contains(self, p):
        return Point.dis(self, p) <= self.r


def main():
    n = int(input())
    points = [Point(*map(int, input().split())) for i in range(n)]

    if n == 1:
        return 0
    if n == 2:
        circle = Circle.line(*points)
        return 2 * circle.r

    ans = 10000
    for cur in comb(points, 2):
        circle = Circle.line(*cur)
        for point in points:
            if not circle.contains(point):
                break
        else:
            ans = min(ans, 2 * circle.r)
    if ans != 10000:
        return ans

    for cur in comb(points, 3):
        circle = Circle.circumcenter(*cur)
        for point in points:
            if not circle.contains(point):
                break
        else:
            ans = min(ans, 2 * circle.r)

    return ans


print(f"{main():.2f}")
