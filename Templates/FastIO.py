import io
import os
import sys
from Timer import timer


@timer
def bytes_io():
    s = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline().decode()
    print(s, "bytes")


@timer
def sys_io():
    a = sys.stdin.readline()
    print(a, "sys")


print(input().strip(), "normal")
sys_io()
bytes_io()
