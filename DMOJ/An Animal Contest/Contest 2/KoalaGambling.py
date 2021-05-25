# An Animal Contest 2 P4 - Koala Gambling

import sys
input = sys.stdin.readline

t = int(input())

for i in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    if n & 1:
        print(*arr)
    elif arr[0] == arr[-1]:
        print(-1)
    else:
        arr[1], arr[-2] = arr[-2], arr[1]
        print(*arr)