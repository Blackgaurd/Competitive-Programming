# F. Longest Strike

from collections import Counter

""" import sys
sys.stdin = open("input.in", "r")
sys.stdout = open("out.out", "w") """


def solve():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort()
    cnt = Counter(arr)
    ranges = []
    cur = []
    for v, c in cnt.items():
        if c >= k:
            if not cur or v == cur[-1] + 1:
                cur.append(v)
            else:
                ranges.append([*cur])
                cur = [v]
        else:
            if cur:
                ranges.append([*cur])
            cur.clear()
    if cur:
        ranges.append([*cur])

    if not ranges:
        print(-1)
        return

    best = max(ranges, key=lambda r: (r[-1] - r[0]))
    print(best[0], best[-1])


for t in range(int(input())):
    solve()
