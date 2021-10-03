# BlueBook - Calculator


def convert(n, b):
    e = n // b
    q = n % b
    if n == 0:
        return "0"
    elif e == 0:
        return str(q)
    else:
        return convert(e, b) + str(q)


cases = int(input())
for i in range(cases):
    base1 = int(input())
    a = int(input(), base1)
    base2 = int(input())
    b = int(input(), base2)
    res = int(eval(f"{a}{input()}{b}"))
    basef = int(input())
    print(convert(res, basef))
    if i != cases - 1:
        input()
