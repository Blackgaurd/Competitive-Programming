import sys
from bisect import insort
input = sys.stdin.readline

n = int(input())
t = input()
cows = []


def check(x: int) -> bool:
    copy = cows
    cnt = 0
    if copy[0] >= x:
        insort(copy, 1)
        cnt += 1

    for i in range(len(copy) - 1):
        dis = copy[i+1] - copy[i]
        add = dis // (x+1) - 1
        cnt += (add if add >=0 else 0)
        if cnt >= 2:
            return True

    return False


for i in range(len(t)):
    if t[i] == '1':
        cows.append(i + 1)


lo = 1
hi = n
ans = 0
while lo <= hi:
    mid = (lo + hi) // 2
    if check(mid):
        ans = mid
        lo = mid + 1
    else:
        hi = mid - 1

print(ans + 1)