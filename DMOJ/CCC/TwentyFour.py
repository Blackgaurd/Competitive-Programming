# CCC '08 S4 - Twenty-four

from itertools import permutations

def solve():
    ans = 0
    ops = "+-*/"
    arr = [int(input()) for i in range(4)]
    for a, b, c, d in permutations(arr):
        for p1 in ops:
            for p2 in ops:
                for p3 in ops:
                    try:
                        res = eval(f"(({a}{p1}{b}){p2}{c}){p3}{d}")
                        if res == int(res) and int(res) <= 24:
                            ans = max(ans, int(res))
                    except ZeroDivisionError:
                        pass
                    try:
                        res = eval(f"({a}{p1}({b}{p2}{c})){p3}{d}")
                        if res == int(res) and int(res) <= 24:
                            ans = max(ans, int(res))
                    except ZeroDivisionError:
                        pass
                    try:
                        res = eval(f"{a}{p1}(({b}{p2}{c}){p3}{d})")
                        if res == int(res) and int(res) <= 24:
                            ans = max(ans, int(res))
                    except ZeroDivisionError:
                        pass
                    try:
                        res = eval(f"{a}{p1}({b}{p2}({c}{p3}{d}))")
                        if res == int(res) and int(res) <= 24:
                            ans = max(ans, int(res))
                    except ZeroDivisionError:
                        pass
    return ans


for i in range(int(input())):
    print(solve())