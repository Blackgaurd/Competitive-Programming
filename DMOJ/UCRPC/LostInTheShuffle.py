# UCRPC F21 B - Lost in the Shuffle

arr = [1] * 5
arr[2] = 0

for i in range(int(input())):
    a, b = map(int, input().split())
    arr[a - 1], arr[b - 1] = arr[b - 1], arr[a - 1]

print(arr.index(0) + 1)
