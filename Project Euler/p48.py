n = 1000
m = int(1e10)

ans = 0
for i in range(1, n + 1):
    ans += pow(i, i, m)
    ans %= m

print(ans)
