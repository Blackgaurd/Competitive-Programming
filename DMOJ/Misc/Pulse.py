# Pulse

import sys
input = sys.stdin.readline

n, s, t = map(int, input().split())
ans = sum(s <= 2 * int(input()) <= t for i in range(n))
print(ans)