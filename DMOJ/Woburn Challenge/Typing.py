# WC '97 P4 - Typing

from collections import Counter
from string import ascii_lowercase

a = Counter(ascii_lowercase)

def check(s):
    if len(s) != 26:
        return False
    return Counter(s) == a

for i in range(int(input())):
    print("OK." if check(input()) else "Nope.")