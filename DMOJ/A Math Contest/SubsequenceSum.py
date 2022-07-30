# A Math Contest P2 - Subsequence Sum

MOD = int(1e9 + 7)
n = int(input())
ans = sum(map(int, input().split())) % MOD
ans = (ans * pow(2, n - 1, MOD)) % MOD
print(ans)
