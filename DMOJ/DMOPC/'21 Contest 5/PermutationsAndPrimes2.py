# DMOPC '21 Contest 5 P2 - Permutations & Primes

n = int(input())
if n == 1:
    print(1)
elif n == 2:
    print(-1)
else:
    print("1 3 2", *range(4, n + 1))
