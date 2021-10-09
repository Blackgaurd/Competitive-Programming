# A. Gamer Hemose

for _ in range(int(input())):
    n, h = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort(reverse=True)
    a, b = arr[0], arr[1]
    ans, h = divmod(h, a+b)
    ans *= 2
    if h > 0:
        h -= a
        ans += 1
    if h > 0:
        ans += 1
    print(ans)