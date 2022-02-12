# Mock CCC '22 Contest 2 J4 - Hockey Bracket

import sys
input = sys.stdin.readline

n, s = map(int, input().split())
num_groups = n // s
groups = [None for i in range(num_groups)]
points = [0 for i in range(n + 1)]
for i in range(num_groups):
    groups[i] = list(map(int, input().split()))

for i in range((s - 1) * n // 2):
    a, b, r = input().split()
    a = int(a)
    b = int(b)
    if r == "W":
        points[a] += 3
    elif r == "L":
        points[b] += 3
    else:
        points[a] += 1
        points[b] += 1

k = int(input())
ans = []
for i in range(num_groups):
    groups[i].sort(key=lambda x: (-points[x], x))
    ans.append(groups[i][k - 1])

print(*ans)
