import sys

input = sys.stdin.readline

n, k = map(int, input().split())
pre = [0]
top = [0 for i in range(k)]
bot = [0 for i in range(k)]
ans = 0

nums = list(map(int, input().split()))
for i in range(1, n + 1):
    pre.append((pre[i - 1] + nums[i - 1])%k)
    if bot[pre[i]] == 0:
        bot[pre[i]] = i
    else:
        top[pre[i]] = max(top[pre[i]], i)

    ans = max(ans, top[pre[i]]-bot[pre[i]])

print(ans)
