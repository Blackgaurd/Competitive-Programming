# CCC '20 S2 - Escape Room

import sys
from collections import deque
input = sys.stdin.readline

MM = int(1e6 + 5)
vis = [False for i in range(MM)]
adj = [[] for i in range(MM)]

n = int(input())
m = int(input())

q = deque()
for i in range(1, n + 1):
    for j in range(1, m + 1):
        a = int(input())
        adj[i * j].append(a)
        if i == j == 1:
            q.append(a)
            vis[a] = True

while q:
    cur = q.pop()
    if cur == m * n:
        print("yes")
        sys.exit(0)
    for nxt in adj[cur]:
        if not vis[nxt]:
            vis[nxt] = True
            q.append(nxt)

print("no")