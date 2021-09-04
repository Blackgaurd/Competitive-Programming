# Bob's Blocks

n, m = map(int, input().split())

arr = [list(map(int, input().split())) for i in range(n)]
mx = max(map(max, arr))

ans = 0
for i in arr:
    for j in i:
        ans += mx - j

print(ans)