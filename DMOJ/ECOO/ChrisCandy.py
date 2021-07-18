# ECOO '21 P4 - Chris' Candy

from math import sqrt


def main():
    k = int(input()) + 1
    cop = k

    # prime factorize (input+1)
    fac = {}
    if not k&1:
        fac[2] = 0
    while not k&1:
        fac[2] += 1
        k >>= 1

    for i in range(3, int(sqrt(k))+1):
        if not k%i:
            fac[i] = 0
        while not k%i:
            fac[i] += 1
            k //= i

    if k != 1:
        fac[k] = 1

    if sum(fac.values()) == 1:
        # k is prime
        if cop <= 100000:
            print(cop-1)
            for i in range(cop-1):
                print(1, end=' ')
        else:
            print("Sad Chris")
    else:
        ind = 1
        ans = 0
        output = {}
        for val, cnt in fac.items():
            for _ in range(cnt):
                ans += val-1
                output[ind] = val-1
                ind += 1
            if ans > 100000:
                print("Sad Chris")
                return
        print(ans)
        for val, cnt in output.items():
            for _ in range(cnt):
                print(val, end=' ')

main()
