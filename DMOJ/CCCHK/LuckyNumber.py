# CCCHK '08 J2 - Lucky Number

length = int(input())


def add(n):
    s = 0
    int(n)
    while n:
        s += n % 10
        n //= 10
    if s > 9:
        return add(s)
    return str(s)


num = ""
for x in range(length):
    num += add(int(input())) + "\n"

print(num)
