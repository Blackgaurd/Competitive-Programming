# CCC '17 J3 - Exactly Electrical

import sys

h = sys.stdin.readline

a = tuple(map(int, h().split()))
b = tuple(map(int, h().split()))
dis = int(h())
trav = abs(a[0] - b[0]) + abs(a[1] - b[1])

print("Y" if dis >= trav and not (trav - dis) % 2 else "N")
