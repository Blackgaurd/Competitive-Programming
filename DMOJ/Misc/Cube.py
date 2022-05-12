# ACSL '09 Practice P7 - Cube

import sys


nets = [
    [(0, 1), (1, 1), (2, 1), (3, 1), (1, 2), (1, 0)],
    [(0, 1), (0, 0), (1, 1), (0, 2), (2, 1), (3, 1)],
    [(0, 1), (1, 1), (2, 1), (3, 1), (0, 0), (2, 2)],
    [(0, 1), (1, 1), (2, 1), (3, 1), (1, 0), (2, 2)],
    [(0, 1), (1, 1), (2, 1), (3, 1), (3, 0), (0, 2)],
    [(0, 1), (1, 1), (2, 1), (3, 1), (1, 0), (0, 2)],
    [(0, 0), (0, 1), (1, 1), (2, 1), (2, 2), (3, 2)],
    [(0, 0), (1, 0), (1, 1), (2, 1), (2, 2), (3, 2)],
    [(1, 0), (0, 1), (1, 1), (2, 1), (2, 2), (3, 2)],
    [(2, 0), (0, 1), (1, 1), (2, 1), (2, 2), (3, 2)],
    [(0, 0), (1, 0), (2, 0), (2, 1), (3, 1), (4, 1)],
]

nets2 = [
    [(0, 1, "A"), (1, 1, "B"), (2, 1, "A"), (3, 1, "B"), (1, 2, "C"), (1, 0, "C")],
    [(0, 1, "B"), (0, 0, "A"), (1, 1, "C"), (0, 2, "A"), (2, 1, "B"), (3, 1, "C")],
    [(0, 1, "A"), (1, 1, "B"), (2, 1, "A"), (3, 1, "B"), (0, 0, "C"), (2, 2, "C")],
    [(0, 1, "A"), (1, 1, "B"), (2, 1, "A"), (3, 1, "B"), (1, 0, "C"), (2, 2, "C")],
    [(0, 1, "A"), (1, 1, "B"), (2, 1, "A"), (3, 1, "B"), (3, 0, "C"), (0, 2, "C")],
    [(0, 1, "A"), (1, 1, "B"), (2, 1, "A"), (3, 1, "B"), (1, 0, "C"), (0, 2, "C")],
    [(0, 0, "A"), (0, 1, "B"), (1, 1, "C"), (2, 1, "B"), (2, 2, "A"), (3, 2, "C")],
    [(0, 0, "A"), (1, 0, "B"), (1, 1, "C"), (2, 1, "B"), (2, 2, "A"), (3, 2, "C")],
    [(1, 0, "A"), (0, 1, "B"), (1, 1, "C"), (2, 1, "B"), (2, 2, "A"), (3, 2, "C")],
    [(2, 0, "A"), (0, 1, "B"), (1, 1, "C"), (2, 1, "B"), (2, 2, "A"), (3, 2, "C")],
    [(0, 0, "A"), (1, 0, "B"), (2, 0, "A"), (2, 1, "C"), (3, 1, "B"), (4, 1, "C")],
]

for net in nets:
    net.sort()

arr = [input().split() for i in range(6)]
cube = []
d = [(0, 1), (0, -1), (1, 0), (-1, 0)]


def dfs(i, j):
    cube.append((i, j, arr[i][j]))
    arr[i][j] = "0"
    for dx, dy in d:
        nx = i + dx
        ny = j + dy
        if nx < 0 or nx >= 6:
            continue
        if ny < 0 or ny >= 6:
            continue
        if arr[nx][ny] == "0":
            continue
        dfs(nx, ny)


def shift(cube):
    mx = min(cube, key=lambda x: x[0])[0]
    my = min(cube, key=lambda x: x[1])[1]
    cube = [(x - mx, y - my) for x, y in cube]
    return cube


def rotate90(cube):
    cube = [(-y, x) for x, y in cube]
    return shift(cube)


for i in range(6):
    for j in range(6):
        if arr[i][j] != "0":
            dfs(i, j)
            break

if len(arr) != 6:
    print(0)
    sys.exit(0)

cube.sort()


def check():
    global cube
    tmp = [(x, y) for x, y, _ in cube]
    tmp = shift(tmp)
    for i in range(4):
        for j in range(len(nets)):
            if tmp == nets[j]:
                return j
        tmp = rotate90(tmp)
        cube = [(-y, x, num) for x, y, num in cube]
        mx = min(cube, key=lambda x: x[0])[0]
        my = min(cube, key=lambda x: x[1])[1]
        cube = [(x - mx, y - my, num) for x, y, num in cube]

    tmp = [(-x, y) for x, y in tmp]
    tmp = shift(tmp)
    cube = [(-x, y, num) for x, y, num in cube]
    mx = min(cube, key=lambda x: x[0])[0]
    my = min(cube, key=lambda x: x[1])[1]
    cube = [(x - mx, y - my, num) for x, y, num in cube]

    for i in range(4):
        for j in range(len(nets)):
            if tmp == nets[j]:
                return j
        tmp = rotate90(tmp)
        cube = [(-y, x, num) for x, y, num in cube]
        mx = min(cube, key=lambda x: x[0])[0]
        my = min(cube, key=lambda x: x[1])[1]
        cube = [(x - mx, y - my, num) for x, y, num in cube]

    return -1


a = check()
if a == -1:
    print(0)
    sys.exit(0)

mx = min(cube, key=lambda x: x[0])[0]
my = min(cube, key=lambda x: x[1])[1]
cube = [(x - mx, y - my, num) for x, y, num in cube]
cur_net = nets2[a]
mp = {num: (x, y) for x, y, num in cube}
mp2 = {(x, y): c for x, y, c in cur_net}

face = mp2[mp['1']]
for i in range(2, 7):
    if face == mp2[mp[str(i)]]:
        print(i)
