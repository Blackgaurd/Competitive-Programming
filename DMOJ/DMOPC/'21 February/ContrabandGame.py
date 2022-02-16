# DMOPC '21 Contest 6 P5 - Contraband Game
# partials N=1

n, m = map(int, input().split())
MOD = int(1e9) + 7


def solve(t):
    cnt = 1
    ret = 1
    for i in range(m):
        if t[i] != t[i + 1]:
            ret *= pow(2, cnt - 1, MOD)
            ret %= MOD
            cnt = 0
        cnt += 1
    return ret


t = list(input())
t.append(".")
for i in range(m):
    t[i] = "S" if t[i] == "N" else "N"
    print(solve(t), end=" ")
    t[i] = "S" if t[i] == "N" else "N"
