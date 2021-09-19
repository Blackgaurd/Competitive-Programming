from functools import lru_cache
import timeit


@lru_cache
def fib_with_cache(num: int):
    if num <= 1:
        return 1
    return int(fib_with_cache(num-1) + fib_with_cache(num-2))


@lru_cache(maxsize=4)
def fib_with_lru(num: int):
    if num <= 1:
        return 1
    return int(fib_with_lru(num-1) + fib_with_lru(num-2))


def fib_no_memo(num: int):
    if num <= 1:
        return 1
    return int(fib_no_memo(num-1) + fib_no_memo(num-2))


def fib_cache_wrapper():
    fib_with_cache(10)


def fib_lru_wrapper():
    fib_with_lru(10)


def fib_no_memo_wrapper():
    fib_no_memo(10)


print("fib function with num = 10")
print("no functools:                    ", timeit.timeit(fib_no_memo_wrapper))
print("functools cache:                 ", timeit.timeit(fib_cache_wrapper))
print("functools lru cache, maxsize = 4:", timeit.timeit(fib_lru_wrapper))


