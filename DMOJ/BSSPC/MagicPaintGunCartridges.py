# BSSPC '21 J3 - Magic Paint Gun Cartridges

import sys
input = sys.stdin.readline

m, n = map(int, input().split())

r, y, b = 0, 0, 0
red = lambda char: char == 'R' or char == 'O' or char == 'P' or char == 'B'
blue = lambda char: char == 'U' or char == 'G' or char == 'P' or char == 'B'
yellow = lambda char: char == 'Y' or char == 'G' or char == 'O' or char == 'B'

for i in range(n):
    row = input()[:-1]
    if red(row[0]):
        r += 1
    if blue(row[0]):
        b += 1
    if yellow(row[0]):
        y += 1
    for j in range(1, len(row)):
        if red(row[j]):
            if not red(row[j-1]):
                r += 1
        if blue(row[j]):
            if not blue(row[j-1]):
                b += 1
        if yellow(row[j]):
            if not yellow(row[j-1]):
                y += 1

print(r, y, b)