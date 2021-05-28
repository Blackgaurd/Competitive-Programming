# 16 BIT S/W ONLY

import sys
input = sys.stdin.readline

for i in range(int(input())):
    a = list(map(int, input().split()))
    print("POSSIBLE DOUBLE SIGMA" if a[0] * a[1] == a[2] else "16 BIT S/W ONLY")