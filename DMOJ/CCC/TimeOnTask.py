# CCC '13 J4 - Time on task

import sys

mins = int(sys.stdin.readline())
chores = []
for x in range(int(sys.stdin.readline())):
    chores.append(int(sys.stdin.readline()))

chores = sorted(chores)

total, c = 0, 0
for y in chores:
    if y <= mins - total:
        total += y
        c += 1
print(c)
