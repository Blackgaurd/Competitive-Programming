# Ferris Wheel

from collections import deque

n, x = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
q = deque(arr)
ans = 1
while len(q) != 1:
    if q[-1] + q[0] <= x:
        q[-1] += q.popleft()
    else:
        ans += 1
        q.pop()
print(ans)
