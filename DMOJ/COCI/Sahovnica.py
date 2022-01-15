# COCI '12 Contest 3 #1 Sahovnica

r, c = map(int, input().split())
a, b = map(int, input().split())

for i in range(r):
    for x in range(a):
        for j in range(c):
            ch = "X" if (i + j) % 2 == 0 else "."
            print(end=ch * b)
        print()
