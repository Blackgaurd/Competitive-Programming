# Back to School '16: Harambe

import sys

input = sys.stdin.readline
line = input()
up, low = 0, 0
for char in line:
    if char not in [" ", "\n"]:
        if char.isupper():
            up += 1
        else:
            low += 1

if up > low:
    print(line.upper())
elif up < low:
    print(line.lower())
else:
    print(line)
