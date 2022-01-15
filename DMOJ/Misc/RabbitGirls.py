# Rabbit Girls

from math import ceil

n = int(input())
k = int(input())

t = ceil(n / k) * k
b = n // k * k
if b == 0:
    print(abs(n - t))
else:
	print(min(abs(n - b), abs(n - t)))
