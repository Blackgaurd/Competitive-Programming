# Fast Factorial Calculator 2
# python proof of concept


def fact(m, p):
    if m >= p:
        return 0
    if m <= p // 2:
        res = 1
        for i in range(2, m + 1):
            res = res * i % p
        return res
    res = 1
    for i in range(m + 1, p):
        res = res * i % p
    res = pow(res, -1, p)
    res = p - res
    return res % p


p = (1 << 32) - 5
n = int(input())
for i in range(n):
    m = int(input())
    print(fact(m, p))
