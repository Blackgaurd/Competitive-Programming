# CCC '09 S1 - Cool Numbers

from math import pow
import sys

input = sys.stdin.readline
a, b = int(input()), int(input())
if a == 1771561:
    a = 11
else:
    a = pow(a, 1 / 6)
if b == 1771561:
    b = 12
else:
    b = int(pow(b, 1 / 6)) + 1

print(int(b - a))
