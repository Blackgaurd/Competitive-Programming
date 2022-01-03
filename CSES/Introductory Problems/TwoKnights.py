# Two Knights

for n in range(1, int(input()) + 1):
    ans = ((n - 1) * (n ** 3 + (n - 4) ** 2)) // 2
    print(ans)
