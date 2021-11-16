# Candy

n = int(input())
print(*sorted(set(__import__("functools").reduce(list.__add__,
      ([i, n // i] for i in range(1, int(n ** 0.5) + 1) if n % i == 0)))), sep="\n")
