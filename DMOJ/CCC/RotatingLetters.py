# CCC '13 J2 - Rotating letters

import sys

word = input()

letters = "IOSHZXN"

for char in word:
    if char not in letters:
        print("NO")
        sys.exit()

print("YES")
