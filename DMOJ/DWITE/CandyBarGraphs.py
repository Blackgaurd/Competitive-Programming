# DWITE '12 R1 #2 - Candybar Graphs

from math import floor

for i in range(5):
    a, b = map(int, input().split())
    star = floor((a / (a + b)) * 10)
    print("*" * star + "." * (10 - star))
