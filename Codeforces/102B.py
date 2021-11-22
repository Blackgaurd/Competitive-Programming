# B. Sum of Digits

n = int(input())
ans = 0
while n >= 10:
    n = sum(map(int, str(n)))
    ans += 1

print(ans)
