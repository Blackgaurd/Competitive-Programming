# Range XOR Queries

import sys
input = sys.stdin.readline

n, q = map(int, input().split())
arr = [0] + list(map(int, input().split()))
for i in range(1, len(arr)):
    arr[i] ^= arr[i - 1]
for i in range(q):
    a, b = map(int, input().split())
    print(arr[b] ^ arr[a - 1])
