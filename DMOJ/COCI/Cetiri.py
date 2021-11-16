# COCI '07 Contest 3 #1 Cetiri

p = sorted(list(map(int, input().split())))
dif1 = p[1] - p[0]
dif2 = p[2] - p[1]
if dif1 == dif2:
    print(p[2] + dif1)
elif dif1 > dif2:
    print(p[0] + dif2)
else:
    print(p[1] + dif1)
