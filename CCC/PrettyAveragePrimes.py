# CCC '19 S2 - Pretty Average Primes

import sys
from functools import cache
from math import sqrt
input = sys.stdin.readline


@cache
def trialDiv(n: int):
    if n <= 2:
        return n == 2

    if n&1 == 0:
        return False

    for i in range(3, int(sqrt(n))+1, 2):
        if n%i == 0:
            return False
    return True


for _ in range(int(input())):
    a = int(input())
    if trialDiv(a):
        print(a, a)
    else:
        for i in range(3, a):
            if trialDiv(i) and trialDiv(a*2-i):
                print(i, a*2-i)
                break