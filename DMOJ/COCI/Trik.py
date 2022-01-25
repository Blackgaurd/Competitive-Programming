# COCI '06 Contest 5 #1 Trik

a = [1, 0, 0]

for c in input():
    if c == "A":
        a[0], a[1] = a[1], a[0]
    elif c == "B":
        a[1], a[2] = a[2], a[1]
    else:
        a[0], a[2] = a[2], a[0]

print(a.index(1) + 1)
