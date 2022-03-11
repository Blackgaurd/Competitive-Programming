# Avocado Trees!

import sys
input = sys.stdin.readline

n, q, h = map(int, input().split())
psa = [0 for i in range(n + 1)]
for i in range(1, n + 1):
    a, b = map(int, input().split())
    psa[i] = psa[i - 1]
    if a <= h:
        psa[i] += b

ans = 0
for i in range(q):
    a, b = map(int, input().split())
    ans = max(ans, psa[b] - psa[a - 1])

print(ans)
