import time

def timer(func):
    def wrapper(*args, **kwargs):
        __start = time.perf_counter()
        func(*args, **kwargs)
        __end = time.perf_counter()
        print(f'{func.__name__}: {__end - __start} secs')
    return wrapper