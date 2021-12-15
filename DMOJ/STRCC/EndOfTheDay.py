# St Robert Coding Competition J5 - End of the Day

input()
print(__import__("functools").reduce(lambda x, y: x ^ y, map(int, input().split())))
