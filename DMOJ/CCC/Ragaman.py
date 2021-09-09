# CCC '16 S1 - Ragaman

from collections import Counter
from sys import exit

a = Counter(input())
b = Counter(input())
cnt = b['*']

for k, v in a.items():
    dif = v - b[k]
    if dif < 0:
        print('N')
        exit()
    cnt -= dif
    if cnt < 0:
        print('N')
        exit()

print('A')