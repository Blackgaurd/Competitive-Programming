# CCC '15 J4 - Wait Time

import sys

input = sys.stdin.readline

time = 0
arr = [[]]
for i in range(101):
    arr.append([])
for i in range(int(input())):
    t = input().split()
    if t[0] == "R" or t[0] == "S":
        arr[int(t[1])].append(time)
    else:
        time += int(t[1]) - 2
    time += 1

for i in range(1, 101):
    if len(arr[i]) > 0:
        print(i, end=" ")
        if len(arr[i]) % 2 == 1:
            print(-1)
        else:
            sum = 0
            for j in range(1, len(arr[i]), 2):
                sum += arr[i][j] - arr[i][j - 1]
            print(sum)
