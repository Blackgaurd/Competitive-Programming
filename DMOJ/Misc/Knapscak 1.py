import sys

sc = sys.stdin.readline

N, W = map(int, sc().split())
w = [0]
v = [0]
arr = [[-1 for i in range(100001)] for j in range(100)]


def knapsack(n, c):
    if arr[n][c] != -1:
        return arr[n][c]
    result = 0
    if n == 0 or c == 0:
        pass
    elif w[n] > c:
        result = knapsack(n - 1, c)
    else:
        notake = knapsack(n - 1, c)
        take = knapsack(n - 1, c - w[n]) + v[n]
        result = max(take, notake)
    arr[n][c] = result
    return result


for i in range(N):
    a, b = map(int, sc().split())
    w.append(a)
    v.append(b)

print(knapsack(N, W))
