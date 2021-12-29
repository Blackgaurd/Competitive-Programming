# Bob's Math Homework
# consecutive integers that sum to n

n = int(input())

ans = 1
for i in range(2, n // 2 + 2):
    cnt = i * (i - 1) // 2
    if cnt >= n:
        break
    ans += (n - cnt) % i == 0
print(ans)
