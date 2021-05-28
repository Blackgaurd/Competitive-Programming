# pypy2

def bar(n):
    print(n)


type(foo)(type(foo.__code__)(0, 3, 0, 0, foo.__code__.co_code, foo.__code__.co_consts[:5] + (bar.__code__,), foo.__code__.co_names, (), "", "", 0, ""), globals())()