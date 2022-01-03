# An Animal Contest 4 P3 - Snowy Slopes

import sys
from math import gcd

input = sys.stdin.readline

n, m = map(int, input().split())
coords = [tuple(map(int, input().split())) for i in range(n)]
slopes = set()
for i in range(m):
    k, d = map(int, input().split())
    _gcd = gcd(k, d)
    k //= _gcd
    d //= _gcd
    if k < 0 and d > 0:
        k *= -1
        d *= -1
    slopes.add((k, d))

seen = {}
ans = 0
for k, d in slopes:
    for x, y in coords:
        cur = k * x - d * y
        if cur in seen:
            ans += seen[cur]
        else:
            seen[cur] = 0
        seen[cur] += 1
    seen.clear()

print(ans)
