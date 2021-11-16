# Word Scrambler

import sys, itertools

input = sys.stdin.readline

t = input()

a = list(map("".join, itertools.permutations(t[:-1])))
a.sort()
print(*a, sep="\n")
