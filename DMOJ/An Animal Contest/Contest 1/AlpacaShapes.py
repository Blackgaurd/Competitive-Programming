# An Animal Contest 1 P1 - Alpaca Shapes

import sys

s, r = map(int, sys.stdin.readline().split())
print("SQUARE" if s*s > 3.14*r*r else "CIRCLE")