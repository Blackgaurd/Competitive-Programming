# Fast Factorial Calculator

from math import factorial

for i in range(int(input())):
    n = int(input())
    print(0 if n >= 34 else factorial(n) % 2**32)