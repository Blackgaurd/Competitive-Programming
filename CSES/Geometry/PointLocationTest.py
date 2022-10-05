# Point Location Test


def solve():
    # cross product of vectors
    x1, y1, x2, y2, x3, y3 = map(int, input().split())
    x21, y21 = x2 - x1, y2 - y1
    x31, y31 = x3 - x1, y3 - y1

    z = x31 * y21 - x21 * y31
    if z < 0:
        print("LEFT")
    elif z > 0:
        print("RIGHT")
    else:
        print("TOUCH")


for t in range(int(input())):
    solve()
