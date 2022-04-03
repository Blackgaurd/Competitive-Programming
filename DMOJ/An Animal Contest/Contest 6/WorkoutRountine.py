# An Animal Contest 6 P1 - Workout Routine

n, k = map(int, input().split())

ttl = n * (n + 1) // 2
nxt = (ttl // k + 1) * k
add = nxt - ttl
for i in range(1, n):
    print(end=f"{i} ")
print(n + add)
