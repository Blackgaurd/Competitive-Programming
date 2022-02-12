# CCCJQR P2

john_cena = int(input().split()[-1])

n = int(input())
ans = 0
for i in range(n):
    p = int(input().split()[-1])
    ans += john_cena > p

print(ans)
