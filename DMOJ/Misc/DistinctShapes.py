# Disctinct Shapes

from collections import deque


MOD = int(1e9) + 7
n, m = map(int, input().split())
arr = [input() for i in range(n)]
vis = [[False for i in range(m)] for j in range(n)]
_dir = [(0, 1), (0, -1), (1, 0), (-1, 0)]
islands = set()

for i in range(n):
    for j in range(m):
        if not vis[i][j] and arr[i][j] == "#":
            mnx, mny = int(1e4), int(1e4)
            points = []
            q = deque([(i, j)])
            while q:
                cx, cy = q.popleft()
                points.append((cx, cy))
                vis[cx][cy] = True
                mnx = min(mnx, cx)
                mny = min(mny, cy)
                for dx, dy in _dir:
                    nx, ny = cx + dx, cy + dy
                    if nx < 0 or nx >= n or ny < 0 or ny >= m:
                        continue
                    if arr[nx][ny] != "#" or vis[nx][ny]:
                        continue
                    q.append((nx, ny))
            points.sort()
            points = ((x - mnx, y - mny) for x, y in points)

            h1, h2 = 0, 0
            for x, y in points:
                h1 = (h1 * 131 + x) % MOD
                h1 = (h1 * 131 + y) % MOD
                h2 = (h2 * 101 + x) % MOD
                h2 = (h2 * 101 + y) % MOD
            islands.add((h1, h2))

print(len(islands))
