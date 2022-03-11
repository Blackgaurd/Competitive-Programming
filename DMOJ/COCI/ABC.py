# COCI '06 Contest 2 #2 ABC

arr = list(map(int, input().split()))
arr.sort()
for c in input():
    if c == "A":
        print(end=f"{arr[0]} ")
    elif c == "B":
        print(end=f"{arr[1]} ")
    else:
        print(end=f"{arr[2]} ")
