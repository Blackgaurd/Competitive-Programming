# SAC '22 Code Challenge 3 Junior P4 - Normal Conversions

import string

digs = string.digits + string.ascii_letters

q = int(input())


def int2base(x, base):
    if x == 0:
        return digs[0]

    digits = []

    while x:
        digits.append(digs[x % base])
        x = x // base

    digits.reverse()

    return "".join(digits)


for i in range(q):
    b1, n, b2 = map(int, input().split())
    n = int(str(n), b1)
    print(int2base(n, b2))
