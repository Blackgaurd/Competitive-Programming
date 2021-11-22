# A. Next Round

n, k = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort(reverse=True)
print(sum(i >= arr[k - 1] and i > 0 for i in arr))
