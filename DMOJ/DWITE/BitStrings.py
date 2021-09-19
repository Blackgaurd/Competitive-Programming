# DWITE '12 R2 #3 - Bitstrings

from functools import lru_cache

@lru_cache
def s(x: int) -> int:
    if x <= 2:
        return 1
    return s(x-2) + s(x-3)

for i in range(5):
    print(s(int(input())))