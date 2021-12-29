# XOR Sum

from functools import reduce

n = int(input())
arr = list(map(int, input().split()))

mx = sum(arr)
mn = reduce(lambda x, y: x ^ y, arr)
print(mx - mn)
