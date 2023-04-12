n = 1000

a = 1
for i in range(n):
    a *= 2

ttl = 0
while a:
    ttl += a % 10
    a //= 10

print(ttl)
