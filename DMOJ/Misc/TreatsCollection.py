# Treats Collection

n, k = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()


def check(a, b):
    if a < 0 and b < 0:
        return -a
    elif a > 0 and b > 0:
        return b
    return min(-a * 2 + b, 2 * b - a)


ans = 1 << 63
for i in range(k - 1, len(arr)):
    ans = min(ans, check(arr[i - k + 1], arr[i]))

print(ans)
