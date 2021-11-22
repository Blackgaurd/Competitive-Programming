# A. Team

ans = 0
for i in range(int(input())):
    if sum(map(int, input().split())) >= 2:
        ans += 1

print(ans)
