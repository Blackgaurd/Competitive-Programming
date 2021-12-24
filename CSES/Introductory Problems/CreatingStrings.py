# Creating Strings

from itertools import permutations

arr = ["".join(i) for i in set(permutations(input()))]
arr.sort()
print(len(arr))
print(*arr, sep="\n")
