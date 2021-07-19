# CCC '01 S2 - Spirals

a, b = map(int, input().split())
arr = [[-1 for i in range(101)] for i in range(101)]


def fun(i: int, j: int, x: int):
    if x == b + 1:
        return
    arr[i][j] = x

    left = arr[i][j - 1] != -1
    right = arr[i][j + 1] != -1
    up = arr[i - 1][j] != -1
    down = arr[i + 1][j] != -1

    # move left
    if right and not up:
        fun(i, j - 1, x + 1)

    # move down
    elif up and not left:
        fun(i + 1, j, x + 1)

    # move right
    elif left and not down:
        fun(i, j + 1, x + 1)

    # move up
    elif down and not right:
        fun(i - 1, j, x + 1)


arr[50][50] = a
arr[51][50] = a + 1
arr[51][51] = a + 2
fun(50, 51, a + 3)
for row in arr:
    flag = False
    for num in row:
        if num != -1:
            flag = True
            print(num, end=" ")
    if flag:
        print()
