# CPC '21 Contest 1 P2 - AQT and Multiset

import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a.sort()
b.sort()
c = [i^j for i, j in zip(a, b)]

if len(set(c)) == 1:
    print(c[0])
else:
    print(-1)