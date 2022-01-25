# Bubble Cup V9 D Potions homework

n = int(input())
arr = [int(input()) for i in range(n)]
arr.sort()

ans = sum(arr[i] * arr[n - i - 1] for i in range(n)) % 10007
print(ans)
