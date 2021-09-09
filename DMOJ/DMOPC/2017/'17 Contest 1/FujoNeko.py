# DMOPC '17 Contest 1 P1 - Fujō Neko

import sys
input = sys.stdin.readline

r, c = map(int, input().split())
x = [False for i in range(r)]
y = [False for i in range(c)]
for i in range(r):
    a = input()
    for j in range(c):
        if a[j] == 'X':
            x[i] = True
            y[j] = True

for _ in range(int(input())):
    a, b = map(int, input().split())
    print("Y" if x[b-1] or y[a-1] else "N")