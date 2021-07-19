# CCC '97 S1 - Sentences

import sys

input = sys.stdin.readline

for e in range(int(input())):
    n = int(input())
    v = int(input())
    o = int(input())
    nouns = [input()[:-1] for i in range(n)]
    verbs = [input()[:-1] for i in range(v)]
    objects = [input()[:-1] for i in range(o)]
    out = []
    for a in nouns:
        out.append(a)
        for b in verbs:
            out.append(b)
            for c in objects:
                out.append(c + ".")
                print(*out, sep=" ")
                out.pop(-1)
            out.pop(-1)
        out.pop(-1)
