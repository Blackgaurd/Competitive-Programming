# St Robert Coding Competition S1 - Tricky Math


def mod(a, b):
    ret = a % b
    return ret if ret == 0 else ret - b if a < 0 else ret


n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    print(mod(a * b * (a - b), 100000 - 4))
