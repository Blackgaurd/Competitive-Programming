# CCC '01 S2 - Spirals


a, b = int(input()), int(input())
arr = [[-1 for i in range(101)] for j in range(101)]


def fun(i: int, j: int, x: int):
    if x > b:
        return
    arr[i][j] = x

    left = arr[i][j - 1] != -1
    right = arr[i][j + 1] != -1
    up = arr[i - 1][j] != -1
    down = arr[i + 1][j] != -1

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


arr[50][50] = a
if a + 1 <= b:
    arr[51][50] = a + 1
    if a + 2 <= b:
        arr[51][51] = a + 2
        if a + 3 <= b:
            fun(50, 51, a + 3)

# too lazy to do output in a smarter way
out = ""
for row in arr:
    flag = False
    for num in row:
        if num != -1:
            flag = True
            num = str(num)
            out += " " * (2 - len(num)) + num + " "
    if flag:
        out += "\n"

longest = len(max(out.split("\n"), key=len))
for line in out.split("\n")[:-1]:
    if len(line) != longest:
        print(" " * (longest - len(line)), end="")
    print(line)
