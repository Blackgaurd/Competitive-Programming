from functools import lru_cache


@lru_cache
def fib(n):
    if n <= 2:
        return n
    return fib(n - 1) + fib(n - 2)


ttl = 0
for i in range(1, 50):
    if fib(i) <= 4000000:
        if fib(i) % 2 == 0:
            ttl += fib(i)
    else:
        break

print(ttl)
