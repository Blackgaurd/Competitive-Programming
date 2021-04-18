# CCC '96 S4 - When in Rome

import sys

input = sys.stdin.readline

# n = int(input())
values = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}


def to_dec(x):
    ret = 0
    skip = False
    for i in range(len(x)):
        if skip:
            skip = False
            continue
        if i != len(x) - 1 and values[x[i]] < values[x[i + 1]]:
            ret += values[x[i + 1]] - values[x[i]]
            skip = True
        else:
            ret += values[x[i]]
    return ret


def to_roman(x):
    ret = ""
    nums = [1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000]
    roms = ['I', 'IV', 'V', 'IX', 'X', 'XL', 'L', 'XC', 'C', 'CD', 'D', 'CM', 'M']
    i = 12
    while x:
        div = x // nums[i]
        x %= nums[i]
        ret += div * roms[i]
        i -= 1
    return ret

for i in range(int(input())):
    a, b = input()[:-2].split('+')
    x = to_dec(a)
    y = to_dec(b)
    print(f'{a}+{b}={to_roman(x+y) if x+y<=1000 else "CONCORDIA CUM VERITATE"}')
