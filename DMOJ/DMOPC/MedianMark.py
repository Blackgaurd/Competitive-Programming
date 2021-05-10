# DMOPC '14 Contest 1 P1 - Median Mark

import sys
from statistics import median
input = sys.stdin.readline

med = median([int(input()) for i in range(int(input()))])
if med - 0.5 == int(med):
    print(int(med) + 1)
else:
    print(round(med))


