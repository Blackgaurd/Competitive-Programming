# b must be prime for n=0 to work

def isprime(x):
    if x <= 1:
        return False
    if x % 2 == 0:
        return x == 2
    for i in range(3, int(x ** 0.5) + 1, 2):
        if x % i == 0:
            return False
    return True

ans = 0
prod = -1
for b in range(-1000, 1001, 1):
    if not isprime(b):
        continue
    for a in range(-1000, 1001, 1):
        n = 0
        while isprime(n * n + a * n + b):
            n += 1

        if n > ans:
            ans = n
            prod = a * b

print(prod)