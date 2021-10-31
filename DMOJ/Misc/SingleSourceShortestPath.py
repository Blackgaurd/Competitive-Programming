# Single Source Shortest Path

from queue import PriorityQueue

n, m = map(int, input().split())

adj = [[] for i in range(n + 1)]

for i in range(m):
    a, b, w = map(int, input().split())
    adj[a].append([w, b])
    adj[b].append([w, a])

dis = [int(1e9) for i in range(n + 1)]
dis[1] = 0
q = PriorityQueue()
q.put((0, 1))

while not q.empty():
    d, cur = q.get()
    for w, nxt in adj[cur]:
        if dis[cur] + w < dis[nxt]:
            dis[nxt] = dis[cur] + w
            q.put((dis[nxt], nxt))

for i in range(1, n + 1):
    if dis[i] == int(1e9):
        print(-1)
    else:
        print(dis[i])
