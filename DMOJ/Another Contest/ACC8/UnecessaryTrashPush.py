# Another Contest 8 Problem 2 - Unnecessary Trash Push

import sys

input = sys.stdin.readline

for i in range(int(input())):
    n, k = map(int, input().split())
    trash = 0
    ans = 0
    for a in map(int, input().split()):
        trash += a
        if trash >= k:
            trash = 0
            ans += 1
    print(ans)
