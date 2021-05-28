# ECOO '19 R1 P2 - L-Systems Go

import sys
input = sys.stdin.readline

for e in range(10):
    r, t, a = input().split()

    cnt = [0 for i in range(27)]
    coms = {}
    start = a[0]
    end = a[-1]

    for char in a:
        cnt[ord(char)-64] += 1

    for i in range(int(r)):
        c, s = input().split()
        coms[c] = s

    for i in range(int(t)):
        start = coms[start][0]
        end = coms[end][-1]

        tmp = [0 for j in range(27)]
        for j in range(1, 27):
            if cnt[j]:
                for char in coms[chr(j+64)]:
                    tmp[ord(char)-64] += cnt[j]

        cnt = tmp

    print(start + end, sum(cnt))
