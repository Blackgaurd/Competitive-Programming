# Getting Snappy

n, m = map(int, input().split())

arr = []
while n != 0:
    arr.append(n // 2)
    n //= 2

print(min(arr, key=lambda x: (abs(x - m), m - x)))
