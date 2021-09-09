# DMOPC '20 Contest 4 P2 - Beautiful Grids

import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())

row = set(())
col = set(())
rl = []
cl = []
for i in range(k):
    r, c = map(int, input().split())
    rl.append(r)
    cl.append(c)

rl.sort()
cl.sort()
print(rl, cl)

i = 0
while i <= len(rl) - 1:
    print(i, rl[i])
    if rl[i] == rl[i+1]:
        i+=2
    else:
        row.add(rl[i])
        i+=1

i = 0
while i <= len(cl) - 1:
    if cl[i] == cl[i+1]:
        i+=2
    else:
        col.add(cl[i])
        i+=1

print(max(len(row), len(col)))

while row and col:
    print(row.pop(), col.pop())

if row:
    while row:
        print(row.pop(), 1)
elif col:
    while col:
        print(col.pop(), 1)
