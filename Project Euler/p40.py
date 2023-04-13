n = 1

num = ""
while len(num) <= 1000000:
    num += str(n)
    n += 1

ans = 1
for e in range(7):
    ans *= int(num[10 ** e - 1])

print(ans)