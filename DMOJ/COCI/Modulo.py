# COCI '06 Contest 1 #1 Modulo

import sys

mods = set(())
for n in range(10):
    mods.add(int(sys.stdin.readline()) % 42)
print(len(mods))
