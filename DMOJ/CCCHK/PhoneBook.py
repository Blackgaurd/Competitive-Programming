# CCCHK '08 J3 - Phone book

import sys
from statistics import multimode

input = sys.stdin.readline
nums = {}
for i in range(int(input())):
    x = input().split()
    nums[int(x[1])] = x[0]

n = []
for j in range(int(input())):
    n.append(int(input()))
print(nums[min(multimode(n))])
