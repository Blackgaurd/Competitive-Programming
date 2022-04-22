# DMOPC '21 Contest 7 P2 - Knitting Scarves

import sys

input = sys.stdin.readline

n, q = map(int, input().split())
after = [i + 1 for i in range(n + 1)]
before = [i - 1 for i in range(n + 2)]

for i in range(q):
    a, b, k = map(int, input().split())
    if after[k] == a:
        continue

    tmp = after[k]
    tmp2 = after[b]
    tmp3 = before[a]
    before[tmp] = b
    after[k] = a

    after[tmp3] = tmp2
    before[tmp2] = tmp3

    after[b] = tmp
    before[a] = k

i = 0
for _ in range(n):
    i = after[i]
    print(i, end=" ")
