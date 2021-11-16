# USACO 2019 December Bronze P1 - Cow

import sys

input = sys.stdin.readline

n = list(map(int, input().split()))

arr = []
ex = []
for i in range(n[0]):

    nums = list(map(int, input().split()))
    for x in range(n[1] - 1, -1, -1):
        for y in range(x - 1, -1, -1):
            tup = (nums[y], nums[x])
            if tup not in arr:
                if tup[::-1] in arr:
                    arr.remove(tup[::-1])
                    ex.append(tup)
                    ex.append(tup[::-1])
                elif tup not in ex:
                    arr.append(tup)

print(len(arr))
