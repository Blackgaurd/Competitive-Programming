# CCC '01 S2 - Spirals (Exact Version)

import sys

# sys.stdin = open("input.txt", "r")
# sys.stdout = open("output.txt", "w")

MM = 101

def solve():
    a, b = map(int, input().split())
    arr = [[0 for i in range(MM)] for j in range(MM)]

    def fun(i: int, j: int, x: int):
        if x > b:
            return
        arr[i][j] = x

        left = arr[i][j - 1] != 0
        right = arr[i][j + 1] != 0
        up = arr[i - 1][j] != 0
        down = arr[i + 1][j] != 0

        if down and left or not down and not right and not up and left:
            # move up
            fun(i - 1, j, x + 1)
        elif down:
            # move left
            fun(i, j - 1, x + 1)
        elif right:
            # move down
            fun(i + 1, j, x + 1)
        elif up:
            # move right
            fun(i, j + 1, x + 1)

    arr[MM // 2][MM // 2] = a
    if a + 1 <= b:
        arr[MM // 2 + 1][MM // 2] = a + 1
        if a + 2 <= b:
            arr[MM // 2 + 1][MM // 2 + 1] = a + 2
            if a + 3 <= b:
                fun(MM // 2, MM // 2 + 1, a + 3)

    # too lazy to do output in a smarter way
    col_max = [0 for i in range(MM)]
    for i in range(MM):
        for j in range(MM):
            col_max[j] = max(col_max[j], arr[i][j])

    out = ""
    add_whitespace = False
    for i in range(MM - 1):
        flag = False
        for j in range(MM - 1):
            if arr[i][j] != 0:
                flag = True
                out += f"{' ' * (len(str(col_max[j])) - len(str(arr[i][j])))}{arr[i][j]} "
            elif arr[i][j + 1] != 0 and (arr[i + 1][j] != 0 or arr[i-1][j] != 0):
                add_whitespace = True
        if flag:
            out += "\n"

    #print(f"{add_whitespace=}")
    longest = len(max(out.split("\n"), key=len))
    for line in out.split("\n")[:-1]:
        if add_whitespace and len(line) != longest:
            print(" " * (longest - len(line)), end="")
        print(line.rstrip())

n = int(input())
for i in range(n):
    solve()
    if i != n-1:
        print()
