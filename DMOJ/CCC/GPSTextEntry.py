# CCC '08 J3 - GPS Text Entry

import sys
import string

chars = string.ascii_uppercase + " -.\n"
x, y = 0, 0
ans = 0
for c in sys.stdin.readline():
    pos = chars.index(c)
    nx, ny = divmod(pos, 6)
    ans += abs(x - nx) + abs(y - ny)
    x = nx
    y = ny
print(ans)
