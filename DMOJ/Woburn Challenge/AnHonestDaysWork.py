# WC '18 Contest 3 J1 - An Honest Day's Work

import operator

p = int(input())
b = int(input())
d = int(input())
q, m = divmod(p, b)
print(d * q + m)
