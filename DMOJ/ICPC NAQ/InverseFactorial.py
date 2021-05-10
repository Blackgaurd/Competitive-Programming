# ICPC NAQ 2016 G - Inverse Factorial
# Stirling's approximation

from math import log, floor, pi, factorial
import sys


def fun(n: int) -> int:
    # returns length of n!
    return floor((log(n) * (n + 0.5) - n + log(2 * pi) / 2) / log(10)) + 1


length = sys.stdin.readline()
if len(length) <= 4:
    for i in range(1, 7):
        if factorial(i) == int(length):
            print(i)
            break
else:
    length = len(length) - 1
    for i in range(7, 205023):
        if fun(i) == length:
            print(i)
            break