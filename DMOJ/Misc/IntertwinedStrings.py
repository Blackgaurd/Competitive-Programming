# Intertwined Strings
# submit in pypy3

from itertools import combinations

a, b = input().split()

n = len(a)
m = len(b)

ans = set()
for comb in combinations(range(n + m), m):
    cur = ["" for i in range(n + m)]
    for ind, c in zip(comb, b):
        cur[ind] = c
    ai = 0
    for i in range(len(cur)):
        if not cur[i]:
            cur[i] = a[ai]
            ai += 1
    ans.add("".join(cur))

print(*ans, sep="\n")
