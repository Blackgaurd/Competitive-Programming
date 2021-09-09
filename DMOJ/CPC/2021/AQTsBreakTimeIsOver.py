# CPC '21 Contest 1 P6 - AQT's Break Time is Over

import sys
input = sys.stdin.readline

ans = [0, 0, 0]
for i in range(int(input())):
    a = list(map(int, input().split()))
    inds = [i for i in range(3) if a[i] == min(*a)]
    if len(inds) == 1:
        ind = inds[0]
        ans[ind] += a[ind]
    else:
        pass