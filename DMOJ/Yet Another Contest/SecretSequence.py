# Yet Another Contest 2 P2 - Secret Sequence

import sys
from functools import lru_cache

fflush = sys.stdin.flush

n = int(input())
arr = [0 for i in range(n + 1)]


@lru_cache
def query(l, r):
    print(f"? {l} {r}")
    fflush()
    return int(input())


ttl = query(1, n)

# left half
carry = 0
for i in range(1, n // 2 + 1):
    arr[i] = ttl ^ query(i + 1, n) ^ carry
    carry ^= arr[i]

# right half
carry = 0
for i in range(n - 1, n // 2 - (n+1) % 2, -1):
    arr[i + 1] = ttl ^ query(1, i) ^ carry
    carry ^= arr[i + 1]

if n % 2 == 1:
    arr[n // 2 + 1] = ttl ^ query(1, n // 2 + 1) ^ query(n // 2 + 1, n)

print("!", *arr[1:])
