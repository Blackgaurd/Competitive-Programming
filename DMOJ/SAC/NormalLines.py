# SAC '22 Code Challenge 3 Junior P2 - Normal Lines

a, b = map(int, input().split())
c, d = map(int, input().split())

if a == c:
    print("y-axis")
elif b == d:
    print("x-axis")
else:
    print("neither")