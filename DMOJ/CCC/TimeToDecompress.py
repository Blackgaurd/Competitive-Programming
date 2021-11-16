# CCC '19 J2 - Time to Decompress

import sys

input = sys.stdin.readline
for x in range(int(input())):
    line = input().split()
    line[0] = int(line[0])
    print(line[1] * line[0])
