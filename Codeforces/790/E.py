# E. Eating Queries


def solve():
    n, q = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort(reverse=True)
    for i in range(1, n):
        arr[i] += arr[i - 1]
    for i in range(q):
        a = int(input())
        lo = 0
        hi = n - 1
        ans = -2
        while lo <= hi:
            mid = (lo + hi) // 2
            if arr[mid] >= a:
                ans = mid
                hi = mid - 1
            else:
                lo = mid + 1
        print(ans + 1)


for t in range(int(input())):
    solve()
