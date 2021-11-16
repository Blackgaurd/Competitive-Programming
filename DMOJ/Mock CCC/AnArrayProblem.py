# Mock CCC '18 Contest 2 J3/S1 - An Array Problem

import sys

input = sys.stdin.readline

n = int(input())
arr = []

for i in range(n):
    arr.append(int(input()))

if n == 1:
    print(0)
else:
    modifications = 0
    n -= 1
    arr = sorted(arr)
    while arr[n - 1] != 0:
        temp = 1
        if arr[n - 1] != 1:
            temp = arr[n - 1] // 2
        arr[n] -= temp
        arr[n - 1] -= temp
        modifications += temp
        arr = sorted(arr)

    print(modifications)
