# BSSPC '21 J4 - James's Magical Soups
# solution no longer works
# worked during contest bc of terrible test cases LOL

import sys

input = sys.stdin.readline

x, n = map(int, input().split())
ans = 0
for i in range(n):
    t, f = map(int, input().split())
    if t - f <= x:
        ans += 1

print(ans)
