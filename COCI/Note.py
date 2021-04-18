# COCI '09 Contest 1 #1 Note

import sys

a = "1 2 3 4 5 6 7 8\n"
b = "8 7 6 5 4 3 2 1\n"
t = sys.stdin.readline()
if t == a:
    print("ascending")
elif t == b:
    print("descending")
else:
    print("mixed")