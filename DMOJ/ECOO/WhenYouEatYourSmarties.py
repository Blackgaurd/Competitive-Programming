# ECOO '15 R1 P1 - When You Eat Your Smarties

from collections import defaultdict

cases = 10
for i in range(cases):
    red = 0
    other = defaultdict(lambda: 0)
    while cur := input():
        if cur[0] == "r":
            red += 1
        elif cur[0] == "e":
            break
        else:
            other[cur] += 1
    ttl = red * 16
    for val in other.values():
        ttl += 13 * ((val + 6) // 7)
    print(ttl)
