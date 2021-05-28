# Connected Components

import sys
input = sys.stdin.readline

n = int(input())
p = [i for i in range(n+1)]

def flead(x):
    if p[x] != x:
        p[x] = flead(p[x])
    return p[x]

for i in range(1, n+1):
    a = list(map(int, input().split()))
    for j in range(1, n+1):
        if a[j-1] == 1:
            if flead(i) != flead(j):
                p[flead(i)] = flead(j)

for i in range(1, n+1):
    if p[i] == 0:
        continue
    print(i, end=' ')
    for j in range(i+1, n+1):
        if p[j] == p[i]:
            print(j, end=' ')
            p[j] = 0
    p[i] = 0
    print()