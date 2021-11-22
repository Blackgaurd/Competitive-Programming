# A. Almost Prime

n = int(input())
MM = n // 2 + 1

prime = [True for i in range(MM)]
primes = []
for i in range(2, MM):
    if prime[i]:
        for j in range(i+i, MM, i):
            prime[j] = False
        primes.append(i)

ans = 0
for i in range(6, n + 1):
    cnt = 0
    for p in primes:
        if i % p == 0:
            cnt += 1
    if cnt == 2:
        ans += 1

print(ans)
