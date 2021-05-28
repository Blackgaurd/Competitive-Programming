# Appleby Contest '20 P1 - Terrific Triangles

import sys
input = sys.stdin.readline

for i in range(int(input())):
    sides = list(map(int, input().split()))
    sides.sort()

    comp = sides[2]**2 - sides[0]**2 - sides[1]**2
    if comp == 0:
        print('R')
    elif comp < 0:
        print('A')
    else:
        print('O')
