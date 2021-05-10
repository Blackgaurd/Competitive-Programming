import sys
from itertools import *
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
ttl = sum(arr)
sol = 100000
for i in range(1, n+1):
    for j in list(combinations(arr, i)):
        #print(j, sum(j))
        sol = min(sol, abs(sum(j)*2-ttl))

print(sol)
