# UTS Open '15 #3 - Pogo

import sys
from functools import cache

sys.setrecursionlimit(int(1e5))

MOD = int(1e9) + 7


@cache
def f(n):
    return max(n, 0) if n <= 1 else (f(n - 1) + f(n - 3)) % MOD


@cache
def a(n):
    if n == 1:
        return 1
    if n <= 0:
        return 0
    return (a(n - 1) + b(n - 2) + c1(n - 3)) % MOD


@cache
def b(n):
    return 0 if n <= 0 else (a(n - 2) + c2(n - 3) + d(n - 1) + d(n - 3)) % MOD


@cache
def c1(n):
    return 0 if n <= 0 else (a(n - 2) + c2(n)) % MOD


@cache
def c2(n):
    return 0 if n <= 0 else (a(n - 1) + a(n - 2) + c2(n - 3) + d(n - 1) + d(n - 3)) % MOD


@cache
def d(n):
    return 0 if n <= 0 else (a(n) + b(n - 1)) % MOD

n, m = map(int, input().split())
if m == 1:
    print(1)
elif m == 2:
    print(f(n))
else:
    print(a(n))
