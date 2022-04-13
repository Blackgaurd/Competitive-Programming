# System Solver

from math import gcd as __gcd
from functools import reduce

# n = variables
# m = equations
n, m = map(int, input().split())

augmented = []
for i in range(m):
    cur = list(map(int, input().split()))

    # reduce equation to lowest terms
    gcd = reduce(__gcd, cur)
    if gcd != 1:
        for elem in range(len(cur)):
            cur[elem] //= gcd

    # check if equation already exists
    for other in augmented:
        if cur == other:
            break
    else:
        augmented.append(cur)


def eq(a, b):
    EPS = 1e-6
    return abs(a - b) < EPS


def solve(a):
    n = len(a)
    m = len(a[0]) - 1

    where = [-1 for i in range(m)]

    col = 0
    row = 0
    while col < m and row < n:
        sel = row
        for i in range(row, n):
            if abs(a[i][col]) > abs(a[sel][col]):
                sel = i
        if eq(a[sel][col], 0):
            col += 1
            continue
        for i in range(col, m + 1):
            a[sel][i], a[row][i] = a[row][i], a[sel][i]
        where[col] = row

        for i in range(n):
            if i == row:
                continue
            c = a[i][col] / a[row][col]
            for j in range(col, m + 1):
                a[i][j] -= a[row][j] * c
        col += 1
        row += 1

    ans = [0 for i in range(m)]
    for i in range(m):
        if where[i] != -1:
            ans[i] = a[where[i]][m] / a[where[i]][i]
    for i in range(n):
        ttl = sum(ans[j] * a[i][j] for j in range(m))
        if not eq(ttl, a[i][m]):
            return 0, []

    if any(where[i] == -1 for i in range(m)):
        return 2, []
    return 1, ans


res, ans = solve(augmented)
if res == 1:
    print(*ans, sep="\n")
else:
    print("NO UNIQUE SOLUTION")
