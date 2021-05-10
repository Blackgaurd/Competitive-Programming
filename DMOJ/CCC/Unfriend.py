# CCC '11 J5 - Unfriend

import sys
from itertools import combinations

input = sys.stdin.readline

n = int(input())
tmp = [i for i in range(1, n)]
cases = []
adj = [[] for i in range(n + 1)]
for i in range(1, n + 1):
    for comb in list(combinations(tmp, i)):
        cases.append(set(comb))

for i in range(1, n):
    adj[int(input())].append(i)


def check(test):
    vis = test
    vis.add(n)
    q = [n]
    while len(q):
        cur = q.pop()
        #print(cur)
        for nxt in adj[cur]:
            if nxt not in vis:
                vis.add(nxt)
                q.append(nxt)
    for i in range(1, n + 1):
        if i not in vis:
            return False
    return True


ans = 1  # one extra for empty case
for comb in cases:
    if check(comb):
        ans += 1
print(ans)
