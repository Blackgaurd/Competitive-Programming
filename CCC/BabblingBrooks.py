# CCC '00 S2 - Babbling Brooks

import sys
input = sys.stdin.readline

n = int(input())
m = [0]
for i in range(n):
    m.append(int(input()))

while (True):
    n = int(input())
    if n==77:
        m.pop(0)
        for i in m:
            print(round(i), end=" ")
        break
    elif n==99:
        a = int(input())
        b = 1-(int(input())/100)
        m.insert(a+1,m[a]*b)
        m[a]-=m[a+1]
    elif n==88:
        a = int(input())
        m[a]+=m.pop(a+1)

