# CPC '21 Contest 1 P3 - AQT and Circles

import sys

input = sys.stdin.readline

for i in range(int(input())):
    r1, r2, r3 = map(int, input().split())

    possible = (r2 - r3) ** 2
    # space between c1 and c2
    if r2 - r1 > 2 * r3:
        inner = (r1 - r3) ** 2
        mid = (r1 + r3) ** 2
        outer = (r2 - r3) ** 2
        valid = inner + outer - mid
    elif r1 >= r3:
        valid = (r1 - r3) ** 2
    else:
        # take min of possible and valid for valid
        valid = (r3 - r1) ** 2
        valid = min(valid, possible)

    print(valid / possible)
