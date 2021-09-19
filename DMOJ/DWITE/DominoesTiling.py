# DWITE '10 R3 #3 - Dominos Tiling

from sys import stdin
from functools import lru_cache

@lru_cache
def f(n:int) -> int:
    if n&1:
        return 0
    if n == 0:
        return 1
    return f(n-2) + 2 * g(n-1)


@lru_cache
def g(n:int) -> int:
    if n == 0 or n == 1:
        return n
    return f(n-1) + g(n-2)

for i in range(5):
    x = int(stdin.readline())
    print(0 if x == 0 else f(x)%1000000)