from collections import deque

arr = []

with open("p81.txt", "r") as f:
    for line in f:
        arr.append(list(map(int, line.split(","))))

n = 80
d2 = ((1, 0), (0, 1))

dis = [[1e9 for i in range(n)] for j in range(n)]
inque = [[False for i in range(n)] for j in range(n)]
q = deque()

dis[0][0] = arr[0][0]
q.append((0, 0))
while q:
    cx, cy = q.popleft()
    inque[cx][cy] = False
    for dx, dy in d2:
        nx, ny = cx + dx, cy + dy
        if nx >= 80 or ny >= 80:
            continue
        if dis[cx][cy] + arr[nx][ny] < dis[nx][ny]:
            dis[nx][ny] = dis[cx][cy] + arr[nx][ny]
            if not inque[nx][ny]:
                inque[nx][ny] = True
                q.append((nx, ny))

print(dis[n - 1][n - 1])
