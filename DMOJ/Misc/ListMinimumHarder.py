# List Minimum (Harder)

n = int(input())
arr = [input() for i in range(n)]
arr.sort()

print(*arr, sep="\n")