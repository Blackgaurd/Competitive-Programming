# USACO 2020 January Bronze P1 - Word Processor

import sys

input = sys.stdin.readline
n = list(map(int, input().split()))
t = input().split()

arr = []
counter = 0
for word in t:
    counter += len(word)
    if counter > n[1]:
        print(*arr)
        arr.clear()
        arr.append(word)
        counter = len(word)
    else:
        arr.append(word)
print(*arr)
