# Two Sets

n = int(input())
if n % 4 in [1, 2]:
    print("NO")
elif n % 4 == 3:
    print("YES")
    r1 = range(4, 4 + (n - 3) // 4)
    r2 = range(4 + (n - 3) // 4, 4 + (n - 3) // 2)
    ttl = n + 4
    print(len(r1) * 2 + 2)
    print(1, 2, end=" ")
    for i in r1:
        print(i, ttl - i, end=" ")
    print()
    print(len(r2) * 2 + 1)
    print(3, end=" ")
    for i in r2:
        print(i, ttl - i, end=" ")
    print()
else:
    print("YES")
    r1 = range(1, n // 4 + 1)
    r2 = range(n // 4 + 1, n // 2 + 1)
    print(n // 2)
    for i in r1:
        print(i, n - i + 1, end=" ")
    print()
    print(n // 2)
    for i in r2:
        print(i, n - i + 1, end=" ")
