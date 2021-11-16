# COCI '20 Contest 2 #1 Crtanje


def location(grid, loc):
    for row in range(len(grid)):
        if row != loc:
            grid[row].append(".")
    return grid


num = int(input())
ops = input()
mat = [[] for row in range(num * 2)]
at = num
for row in range(num):
    if row == 0:
        if ops[row] == "+":
            mat[at].append("/")
        elif ops[row] == "-":
            mat[at].append("\\")
        elif ops[row] == "=":
            mat[at].append("_")

    else:
        if ops[row] == "+":
            if ops[row - 1] == "+":
                mat[at + 1].append("/")
                at += 1
            else:
                mat[at].append("/")

        elif ops[row] == "-":
            if ops[row - 1] == "+":
                mat[at].append("\\")
            else:
                mat[at - 1].append("\\")
                at -= 1

        elif ops[row] == "=":
            if ops[row - 1] == "+":
                mat[at + 1].append("_")
                at += 1
            else:
                mat[at].append("_")
    mat = location(mat, at)

final = []
for row in mat:
    for i in row:
        if i != ".":
            final += [row]
            break

xd = ""
for row in final[::-1]:
    xd += "".join(row) + "\n"

print(xd[:-1])
