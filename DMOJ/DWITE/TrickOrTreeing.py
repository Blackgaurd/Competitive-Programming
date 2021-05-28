import sys
input = sys.stdin.readline
for k in range(2):
    edges = 0
    depth = 0
    temp = 0
    t = input()
    for char in t:
        if char=='(':
            edges+=2
            temp+=1
            depth = max(depth, temp)
        elif char ==')':
            temp-=1
    t.translate(None, ")")
    t.split()
    print(t)
    #candies = sum(map(int, t.split()))
    #print(2*edges-depth, candies)
