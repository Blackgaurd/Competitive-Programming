from functools import lru_cache

MM = 1_000_000


@lru_cache(maxsize=MM)
def collatz(n):
    if n == 1:
        return 1
    nxt = n // 2 if n % 2 == 0 else 3 * n + 1
    return collatz(nxt) + 1


mx = 0
x = -1
for i in range(1, MM + 1):
    if collatz(i) > mx:
        mx = collatz(i)
        x = i

print(x)
