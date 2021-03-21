import sys
from itertools import combinations
input = sys.stdin.readline


dis = int(input())

c = int(input())
clubs=[]
for i in range(c):
    clubs.append(int(input()))

n = 35
for i in range(0,c+1):
    for comb in list(combinations(clubs,i)):
        #print(comb, sum(comb), len(comb))
        s = sum(comb)
        if s==dis:
            n = min(n,len(comb))


if n==35: print("Roberta acknowledges defeat.")
else: print(f"Roberta wins in {n} strokes.")