# Chores

import sys

input = sys.stdin.readline

n = int(input())
arr = [tuple(map(int, input().split())) for i in range(n)]
arr.sort()

MOD = int(1e9) + 7

cur = 0
ans = 0
for a, b in arr:
    ans += cur * b + a * b * (b + 1) // 2
    ans %= MOD

    cur += a * b
    cur %= MOD
print(ans)
