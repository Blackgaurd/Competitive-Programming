# CCC '98 S2 - Cross Number Puzzle

import os


def fac(x):
    ret = []
    for i in range(1, int(x ** 0.5) + 1):
        if x % i == 0:
            ret.append(i)
            if i * i != x and i != 1:
                ret.append(x // i)
    return ret


with open(
    f"{os.path.dirname(os.path.realpath(__file__))}/CrossNumberPuzzle.txt", "w"
) as f:
    for i in range(1000, 9999 + 1):
        if sum(fac(i)) == i:
            f.write(f"{i} ")
    f.write("\n")
    for i in range(100, 999 + 1):
        if sum(map(lambda x: int(x) ** 3, list(str(i)))) == i:
            f.write(f"{i} ")
    f.write("\n")
