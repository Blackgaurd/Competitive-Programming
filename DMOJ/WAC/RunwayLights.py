import sys

input = sys.stdin.readline

mod = 998244353


def choose(x):
    return (x * (x - 1) * (x - 2) // 6) % mod


n, k = map(int, input().split())
s = input()

w, a, c, wa, wac, aw, awc, ac, acw, ca, caw, cw, cwa, wc, wca = 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

for char in s:
    if char == 'W':
        w += 1
        aw += a
        cw += c
        acw += ac
        caw += ca
    elif char == 'A':
        a += 1
        wa += w
        ca += c
        wca += wc
        cwa += cw
    elif char == 'C':
        c += 1
        wc += w
        ac += a
        awc += aw
        wac += wa

    w %= mod
    a %= mod
    c %= mod
    aw %= mod
    cw %= mod
    acw %= mod
    caw %= mod
    wa %= mod
    ca %= mod
    wca %= mod
    cwa %= mod
    wc %= mod
    ac %= mod
    awc %= mod
    wac %= mod

cnt = 0
cnt += (choose(k + 2) * wac) % mod
cnt %= mod
cnt += (choose(k) * caw) % mod
cnt %= mod
cnt += (choose(k + 1) * acw) % mod
cnt %= mod
cnt += (choose(k + 1) * wca) % mod
cnt %= mod
cnt += (choose(k + 1) * cwa) % mod
cnt %= mod
cnt += (choose(k + 1) * awc) % mod
cnt %= mod
print(int(cnt))
