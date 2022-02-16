# System Solver
# proof of concept in python

from math import gcd as __gcd
import sys

# TODO: handle edge cases n != m

n, m = map(int, input().split())
if m < n:
    print("NO UNIQUE SOLUTION")
    sys.exit(0)

augmented = []
for i in range(m):
    arr = list(map(int, input().split()))

    gcd = __gcd(*arr)
    if gcd != 1:
        for j in range(n + 1):
            arr[j] //= gcd

    for other in augmented:
        if all(arr[j] == other[j] for j in range(n)):
            print("NO UNIQUE SOLUTION")
            sys.exit(0)

    augmented.append(arr)

for i in range(m):
    row1 = augmented[i]
    for j in range(i + 1, m):
        row2 = augmented[j]
        constant = row2[i] / row1[i]
        for k in range(m + 1):
            row2[k] -= constant * row1[k]

ans = [None for i in range(n)]
for i in range(m - 1, -1, -1):
    row = augmented[i]
    for j in range(i + 1, n):
        row[-1] -= row[j] * ans[j]
    ans[i] = row[-1] / row[i]

print(*ans, sep="\n")
