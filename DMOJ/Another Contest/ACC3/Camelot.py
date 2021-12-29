# Another Contest 3 Problem 2 - Camelot

from math import floor, ceil
from statistics import median
import sys

input = sys.stdin.readline

n = int(input())
a, b = [], []
for i in range(n):
    x, y = map(int, input().split())
    a.append(x + y)
    b.append(y - y)

ma, mb = median(a), median(b)
print(ma, mb)

check = lambda curx, cury: sum(
    abs(a[i] - curx) + abs(b[i] - cury) for i in range(len(a))
)

print(
    min(
        check(floor(ma), floor(mb)),
        check(floor(ma), ceil(mb)),
        check(ceil(ma), floor(mb)),
        check(ceil(ma), ceil(mb)),
    )
)
