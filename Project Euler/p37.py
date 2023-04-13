n = 800_000

sieve = [True for i in range(n + 1)]
primes = set()

for i in range(2, n + 1):
    if sieve[i]:
        primes.add(i)
        for j in range(i * 2, n + 1, i):
            sieve[j] = False

trunc = []
for p in primes:
    if p < 10:
        continue
    sp = str(p)
    for l in range(len(sp)):
        a = sp[l:]
        b = sp[:l]
        if not int(a) in primes:
            break
        if b and not int(b) in primes:
            break
    else:
        trunc.append(p)

print(sum(trunc))
