# Olympic Scoring

import math

n, b, s, g = map(int, input().split())

points = b + s * 3 + g * 5
x, y = divmod(n - points + 1, 5)
ans = max(0, x + (not not y))
print(ans)