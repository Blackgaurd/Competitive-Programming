from math import sqrt
import re

mx = int(sqrt(1929394959697989990))
mn = int(sqrt(1020304050607080900))


def check(x):
    if re.match(r"^1\d2\d3\d4\d5\d6\d7\d8\d9\d0$", str(x)):
        return True
    return False


for x in range(mn, mx + 1, 10):
    if check(x**2):
        print(x)
        break
