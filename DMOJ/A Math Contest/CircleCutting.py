# A Math Contest P4 - Circle Cutting
# submit in pypy3

import math


def cap_area(h):
    # area of circle sector
    return math.acos(1 - h) - (1 - h) * math.sqrt(1 - (1 - h) ** 2)


n = int(input())
ERR = 1e-11
ans = []
for i in range(1, (n + 1) // 2):
    a = i / n * math.pi
    lo, hi = 0, 1
    mid: float
    while lo <= hi:
        mid = (lo + hi) / 2
        area = cap_area(mid)
        if abs(a - area) < ERR:
            break
        elif area > a:
            hi = mid
        else:
            lo = mid
    ans.extend((1 - mid, mid - 1))

if n % 2 == 0:
    ans.append(0)
ans.sort()

for i in ans:
    print(i)
