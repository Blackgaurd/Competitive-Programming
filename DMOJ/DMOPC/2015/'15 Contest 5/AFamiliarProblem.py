# DMOPC '18 Contest 5 P3 - A Familiar Problem

n, m = map(int, input().split())
arr = list(map(int, input().split()))

l, ttl, ans = 0, 0, 0
for r in range(len(arr)):
    ttl += arr[r]
    while ttl >= m:
        ttl -= arr[l]
        l += 1
    ans = max(ans, r - l + 1)

print(ans)
