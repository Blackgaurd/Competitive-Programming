# WC '18 Contest 2 S1 - Laser Grid

from bisect import bisect_left
import sys

input = sys.stdin.readline

sx, sy = map(int, input().split())
n, m, c = map(int, input().split())
v = [int(input()) for i in range(n)]
h = [int(input()) for i in range(m)]

v.extend([0, int(1e6)])
h.extend([0, int(1e6)])

v.sort()
h.sort()

indx = bisect_left(v, sx)
indy = bisect_left(h, sy)
lbx, upx = v[indx - 1], v[indx]
lby, upy = h[indy - 1], h[indy]

for i in range(c):
    x, y = map(int, input().split())
    if lbx < x < upx and lby < y < upy:
        print("Y")
    else:
        print("N")
