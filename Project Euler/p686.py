import math

lo, hi = math.log10(1.23), math.log10(1.24)
const = math.log10(2)

n = 678910
j = 0
cnt = 0
while cnt != n:
    j += 1
    if lo < j * const - math.floor(j * const) < hi:
        cnt += 1

print(j)