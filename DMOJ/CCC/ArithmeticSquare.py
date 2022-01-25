# CCC '19 S3 - Arithmetic Square
# i hate this problem

arr = [
    list(map(lambda x: x if x == "X" else int(x), input().split())) for i in range(3)
]


def fill():
    global arr
    change = False
    for t in range(4):
        for i in range(3):
            if arr[i].count("X") == 1:
                ind = arr[i].index("X")
                if ind == 0:
                    d = arr[i][2] - arr[i][1]
                    arr[i][0] = arr[i][1] - d
                elif ind == 1:
                    d = (arr[i][2] - arr[i][0]) // 2
                    arr[i][1] = arr[i][0] + d
                else:
                    d = arr[i][1] - arr[i][0]
                    arr[i][2] = arr[i][1] + d
                change = True

        arr = list(map(list, zip(*arr)))
    return change


def fill2():
    global arr
    for i in range(3):
        for j in range(3):
            if arr[i][j] == "X":
                arr[i][j] = 0
                return


cross = [[1, 1], [0, 1], [1, 0], [2, 1], [1, 2]]

fcnt = lambda: sum(x.count("X") for x in arr)
while fcnt():
    if not fill():
        flag = False
        for i, j in cross:
            if arr[i][j] == "X":
                arr[i][j] = 0
                flag = True
                break
        if not flag:
            fill2()

for i in arr:
    print(*i)
