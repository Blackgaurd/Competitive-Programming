import sys

input = sys.stdin.readline


def ordinal(n):
    n%=100
    if n==12 or n==13:
        return "th"
    n%=10
    if


for e in range(int(input())):
    w, c = list(map(int, input().split()))
    m = {}
    for i in range(w):
        t = input()
        if t in m:
            m[t] += 1
        else:
            m[t] = 1
    print(ordinal(c), "most common words(s):")
    val = set(sorted(m.values()))
    max_ = 0
    count = 0
    for i in val:
        if i > max_:
            max_ = i
            count += 1
            if count == c:
                for pair in m.items():
                    if pair[1] == max_:
                        print(pair[0][:-1])
                break
    print()