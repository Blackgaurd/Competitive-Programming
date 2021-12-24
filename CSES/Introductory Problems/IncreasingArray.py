# Increasing Array

n = int(input())
arr = list(map(int, input().split()))

ans = 0
for i in range(1, len(arr)):
    if arr[i] >= arr[i-1]:
        continue
    ans += arr[i-1] - arr[i]
    arr[i] = arr[i-1]
print(ans)
