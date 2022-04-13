# Yet Another Contest 2 P1 - Betting

for t in range(int(input())):
    a, b, c, d = map(int, input().split())
    if a >= b or c >= d or b / a == d / c:
        print("NO")
    else:
        print("YES")
