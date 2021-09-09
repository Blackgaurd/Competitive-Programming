# Back to School '16: Dodgeball

import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(lambda x: x[0].lower(), input().split()))
arr.append('0')
ans = 0
cur = 0
for i in range(len(arr)-1):
    cur += 1
    if arr[i] != arr[i+1]:
        ans += (cur + 1) * cur // 2
        cur = 0

print(ans % 1000000007)