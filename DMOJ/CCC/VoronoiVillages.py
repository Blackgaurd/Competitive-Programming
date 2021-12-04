# CCC '18 S1 - Voronoi Villages

n = int(input())
arr = [int(input()) for i in range(n)]
arr.sort()

ans = 2e9
for i in range(1, len(arr) - 1):
    ans = min(ans, (arr[i+1] - arr[i-1]) / 2)

print(ans)
