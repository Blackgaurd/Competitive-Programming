n = 1000000
max_w = (n - 1) // 2

ttl = 0
for i in range(1, max_w + 1):
    for j in reversed(range(1, i)):
        if (i + j) % 2 == 1:
            continue
        if i**2 - j**2 <= n:
            ttl += 1
        else:
            break

print(ttl)
