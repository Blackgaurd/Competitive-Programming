# CCC '98 S4 - Lottery


def solve():
    t = input().split()
    while len(t) > 1:
        try:
            ind = t.index("X")
            t[ind] = f"({t[ind-1]} {t[ind]} {t[ind+1]})"
            t.pop(ind + 1)
            t.pop(ind - 1)
        except ValueError:
            break
    while len(t) > 1:
        t[0] = f"({t[0]} {t[1]} {t[2]})"
        t.pop(2)
        t.pop(1)
    print(t[0][1:-1])


n = int(input())

for i in range(n):
    solve()
    if i < n - 1:
        print()
