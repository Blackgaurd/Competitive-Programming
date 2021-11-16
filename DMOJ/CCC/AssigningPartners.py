# CCC '14 S2 - Assigning Partners

import sys

input = sys.stdin.readline
n = int(input())
if n % 2 == 1:
    print("bad")
else:
    l1 = input().split()
    l2 = input().split()
    s = set(())
    for t in zip(l1, l2):
        a = frozenset(t)
        s.add(a)
    if len(s) == n / 2:
        print("good")
    else:
        print("bad")
