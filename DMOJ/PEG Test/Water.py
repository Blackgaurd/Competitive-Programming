a = list(map(int, __import__('sys').stdin.readlines()))
a.sort()
print(a[2] - a[0])
