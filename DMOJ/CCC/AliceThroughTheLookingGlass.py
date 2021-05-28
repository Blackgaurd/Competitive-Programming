# CCC '11 S3 - Alice Through the Looking Glass

import sys
input = sys.stdin.readline


def check(m, x, y) -> bool:
    a = pow(5, m-1)

    if a < x <= 4*a and y <= 2*a:
        if y <= a:
            return True

        if 2*a < x <= 3*a:
            return True

        if m > 1:
            if x > 3*a:
                return check(m-1, x-3*a, y-a)

            return check(m-1, x-a, y-a)

    elif m > 1 and 2*a < x <= 3*a and 2*a < y <= 3*a:
        return check(m-1, x-2*a, y-2*a)

    return False


for _ in range(int(input())):
    m, x, y = map(int, input().split())
    print("crystal" if check(m, x+1, y+1) else "empty")
