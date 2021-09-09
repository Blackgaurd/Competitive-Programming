# Prefix Digits

import sys
input = sys.stdin.readline

t = int(input())
for i in range(t):
    n, k = input().split()

    modn = 10 ** len(n)
    modk = 10 ** len(k)

    n = int(n)
    k = int(k)
    mul = k

    ans = False
    while True:
        k %= modn
        if k == n:
            ans = True
            break

        k *= mul
        if k % modk == mul:
            break

    print("YES" if ans else "NO")