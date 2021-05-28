import sys

input = sys.stdin.readline

n, q = map(int, input().split())
arr = [{i} for i in range(1, n + 1)]
for k in range(q):
    c, a, b = input().split()
    if c == 'A':
        s1, s2 = -1, -1
        for i in range(len(arr)):
            if a in arr[i]:
                s1 = i
            if b in arr[i]:
                s2 = i
        if s1 != s2:
            arr[s1].update(arr[s2])
            arr.remove(arr[s2])
    elif c=='Q':
        flag = False
        for i in range(len(arr)):
            if a in arr[i] and b in arr[i]:
                flag = True
        print("Y" if flag else "N")
