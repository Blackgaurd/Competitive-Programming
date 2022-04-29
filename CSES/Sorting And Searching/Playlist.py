# Playlist

from collections import defaultdict

n = int(input())
arr = list(map(int, input().split()))
last_occur = defaultdict(int)

lp = 0
ans = 0
for i, v in enumerate(arr, start=1):
    lp = max(lp, last_occur[v])
    ans = max(ans, i - lp)
    last_occur[v] = i

print(ans)
