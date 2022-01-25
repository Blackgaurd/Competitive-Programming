# DMOPC '21 Contest 5 P1 - Permutations & Primes

n = int(input())

arr = []
if n == 1:
    arr.append(1)
elif n <= 4:
    arr.append(-1)
else:
    for i in range(2, n + 1, 2):
        if i == 4:
            continue
        arr.append(i)
    arr.extend([4, 5])
    for i in range(1, n + 1, 2):
        if i == 5:
            continue
        arr.append(i)

print(*arr)
