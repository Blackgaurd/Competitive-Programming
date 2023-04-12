n = 1_000_000

sieve = [True for i in range(n + 1)]
primes = set()
for i in range(2, n + 1):
    if sieve[i]:
        primes.add(i)
        for j in range(2 * i, n + 1, i):
            sieve[j] = False

ans = 0
for p in primes:
    sp = str(p)
    for i in range(len(sp)):
        sp = sp[1:] + sp[0]
        if int(sp) not in primes:
            break
    else:
        ans += 1

print(ans)
