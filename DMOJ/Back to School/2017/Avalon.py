# Back to School '17: Avalon

n, d = 1, 1
for i in range(int(input())):
    a, b = map(int, input().split())
    n *= b - a
    d *= b

print(n / d)
