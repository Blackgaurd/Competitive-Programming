# VM7WC '16 #1 Bronze - A New Prime Factorization

n = int(input())
while n % 2 == 0:
    n //= 2
    print(2)

for i in range(3, int(n ** 0.5) + 1, 2):
    while n % i == 0:
        n //= i
        print(i)

if n != 1:
    print(n)
