# BlueBook - Triangle

n = int(input())
arr = []
for i in range(n):
    for j in range(len(arr) - 1):
        arr[j] += arr[j + 1]
    arr.insert(0, 1)
    print(*arr)
