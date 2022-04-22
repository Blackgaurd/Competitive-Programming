# Yet Another Contest 2 P1 - Betting

for t in range(int(input())):
    a, b, c, d = map(int, input().split())
    print("YES" if a * d < b * (d - c) else "NO")
