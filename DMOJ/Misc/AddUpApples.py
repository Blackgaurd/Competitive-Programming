# Add Up Apples

import sys

input = sys.stdin.readline


def sums(prev, sum, ans):
    global n, count
    if sum == n:
        print(ans)
        count += 1
    for i in range(prev, n - sum + 1):
        sums(i, sum + i, str(ans) + "+" + str(i))


n = int(input())
count = 0

for i in range(1, n // 2 + 1):
    sums(i, i, str(n) + "=" + str(i))
print(f"total={count}")
