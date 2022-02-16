# DMOPC '21 Contest 6 P2 - Gacha Luck

n, k = map(int, input().split())
arr = list(map(len, input().split("1")))
arr.sort(reverse=True)
ans = sum(arr[i] for i in range(min(k, len(arr))))
print(ans)
