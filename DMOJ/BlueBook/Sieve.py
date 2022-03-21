# BlueBook - Sieve

n = int(input()) + 1
arr = [1] * n
arr[1] = 0
for i in range(2, n):
    if arr[i]:
        arr[i * 2 : n : i] = [0] * (~-n // i - 1)

print(*arr[1:], sep="\n")
