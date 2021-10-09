# A. Perfectly Imperfect Array

from math import sqrt, floor

for i in range(int(input())):
    input()
    for j in map(int, input().split()):
        if floor(sqrt(j)) != sqrt(j):
            print("YES")
            break
    else:
        print("NO")

