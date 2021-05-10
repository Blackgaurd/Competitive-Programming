import sys
input = sys.stdin.readline

for e in range(int(input())):
    n = int(input())
    v = int(input())
    o = int(input())
    nouns = []
    verbs = []
    objects = []
    for i in range(n):
        nouns.append(input()[:-1])
    for i in range(v):
        verbs.append(input()[:-1])
    for i in range(o):
        objects.append(input()[:-1])
    out = []
    for a in nouns:
        out.append(a)
        for b in verbs:
            out.append(b)
            for c in objects:
                out.append(c+".")
                print(*out, sep = " ")
                out.pop(-1)
            out.pop(-1)
        out.pop(-1)
