# Bob's Rocks

import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
c = {}
for i in arr:
    if i not in c:
        c[i] = 0
    c[i] += i

mx = 0
ans = 0
for k, v in c.items():
    if v > mx:
        mx = v
        ans = k
print(ans)