# USACO 2022 January Bronze P2 - Non-Transitive Dice


class Dice:
    def __init__(self, a, b, c, d):
        self.arr = [a, b, c, d]
        self.arr.sort()

    def __gt__(self, other):
        ret = 0
        for i in self.arr:
            for j in other.arr:
                if i < j:
                    ret -= 1
                elif i > j:
                    ret += 1
        return ret > 0


def bash():
    for a in range(1, 11):
        for b in range(a, 11):
            for c in range(b, 11):
                for d in range(c, 11):
                    yield [a, b, c, d]


for t in range(int(input())):
    arr = list(map(int, input().split()))
    a = Dice(*arr[:4])
    b = Dice(*arr[4:])
    # a > b
    if b > a:
        a, b = b, a
    for comb in bash():
        c = Dice(*comb)
        if b > c and c > a:
            print("yes")
            break
    else:
        print("no")
