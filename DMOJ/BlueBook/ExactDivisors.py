# BlueBook - Exact Divisors

from math import sqrt

n = int(input())
for i in range(1, int(sqrt(n)) + 1):
    if n % i == 0:
        print(i)
        if n // i != i:
            print(n // i)
