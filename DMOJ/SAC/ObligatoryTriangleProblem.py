# SAC '22 Code Challenge 4 Junior P3 - Obligatory Triangle Problem

import math

n, a = map(int, input().split())
a = math.radians(a)
mn = 100
ind = -1
for i in range(n):
    x, y = map(int, input().split())
    cur = math.atan2(y, x)
    cur = min(abs(cur - a), abs(cur + 2 * math.pi - a))
    if cur < mn:
        mn = cur
        ind = i
print(ind + 1)
