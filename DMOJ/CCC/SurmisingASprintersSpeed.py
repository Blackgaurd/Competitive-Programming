import sys
input = sys.stdin.readline

arr = []
for i in range(int(input())):
    arr.append(list(map(int, input().split())))

arr.sort()
ans = 0
for i in range(0, len(arr)-1):
    speed = abs((arr[i][1]-arr[i+1][1])/(arr[i][0]-arr[i+1][0]))
    ans = max(ans, speed)
print(ans)

