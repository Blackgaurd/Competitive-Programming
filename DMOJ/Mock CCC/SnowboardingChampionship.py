# Mock CCC '22 Contest 2 J2 - Snowboarding Championship

n, a, b = map(int, input().split())
tommy, andrew = 0, 0
for i in range(n):
    x, y = map(int, input().split())
    tommy += 1 + int(x < a)
    andrew += 1 + int(y < b)

if tommy == andrew:
    print("Tie!")
elif tommy < andrew:
    print("Tommy wins!")
else:
    print("Andrew wins!")