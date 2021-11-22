# A. Theatre Square

m, n, a = map(int, input().split())

x = m // a + bool(m % a)
y = n // a + bool(n % a)

print(x * y)
