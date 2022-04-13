# CCC '17 S2 - High Tide, Low Tide

n = int(input())
t = sorted(list(map(int, input().split())))
if n % 2 == 0:
    low = t[n // 2 - 1 :: -1]
    high = t[n // 2 :]
    for i in range(n // 2):
        print(low[i], high[i], end=" ")
else:
    l = t.pop(0)
    low = t[n // 2 - 1 :: -1]
    high = t[n // 2 :]
    for i in range(n // 2):
        print(low[i], high[i], end=" ")
    print(l)
