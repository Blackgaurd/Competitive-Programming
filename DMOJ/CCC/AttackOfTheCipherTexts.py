# CCC '06 S2 - Attack of the CipherTexts

import sys

input = sys.stdin.readline
a, b, c = input(), input(), input()
for char in c:
    if char == " ":
        print(" ", end="")
    elif char in b:
        print(a[b.index(char)], end="")
    else:
        print(".", end="")
