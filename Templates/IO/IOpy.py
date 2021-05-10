import io
import os
import sys

# sys
input = sys.stdin.readline

# io/os
# does not work for some reason
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
n = input.decode()
