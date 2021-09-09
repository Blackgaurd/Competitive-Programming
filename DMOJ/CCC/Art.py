# CCC '20 J3 - Art

maxx, maxy = 0, 0
minx, miny = 100, 100

for i in range(int(input())):
    a, b = map(int, input().split(","))
    maxx = max(maxx, a)
    minx = min(minx, a)
    maxy = max(maxy, b)
    miny = min(miny, b)

print(f"{minx-1},{miny-1}\n{maxx+1},{maxy+1}")
