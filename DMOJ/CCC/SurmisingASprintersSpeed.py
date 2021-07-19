# CCC '20 S1 - Surmising a Sprinter's Speed

import sys

input = sys.stdin.readline

arr = [list(map(int, input().split())) for i in range(int(input()))]
arr.sort()
ans = 0
for i in range(len(arr) - 1):
    speed = abs((arr[i][1] - arr[i + 1][1]) / (arr[i][0] - arr[i + 1][0]))
    ans = max(ans, speed)
print(ans)
