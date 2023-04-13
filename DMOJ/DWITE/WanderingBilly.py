# DWITE '11 R2 #1 - Wandering Billy


def solve():
    n = int(input())
    pos = [0, 0]
    for i in range(1, n + 1):
        if i % 2 == 1:
            pos[0] += i
        else:
            pos[1] -= i
        if pos[0] - pos[1] >= n:
            break
    if pos[0] > -pos[1]:
        pos[0] -= pos[0] - pos[1] - n
    elif pos[0] < -pos[1]:
        pos[1] += pos[0] - pos[1] - n
    print(*pos)


for i in range(5):
    solve()
