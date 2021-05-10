import sys
from itertools import permutations

input = sys.stdin.readline

q = input()[:-1]
search = input()[:-1]

total = 0
for perm in list(permutations(q)):
    print(str(perm))
    if search.count(perm) != 0:
        total+=1

print(total)
