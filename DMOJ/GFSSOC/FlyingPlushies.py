# GFSSOC '14 Winter J1 - Flying Plushies

n = int(input())
m = int(input())
print(sum(int(input()) >= n for i in range(m)))
