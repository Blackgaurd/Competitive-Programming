# VM7WC '16 #3 Gold - Hello, Officer.

from queue import Queue

n, m, b, qq = map(int, input().split())
MM = n + 1
MX = 1000000000

adj = [[] for i in range(MM)]
inque = [False for i in range(MM)]
dis = [MX for i in range(MM)]
q = Queue()

for i in range(m):
    a, b_, w = map(int, input().split())
    adj[a].append((w, b_))
    adj[b_].append((w, a))

q.put(b)
dis[b] = 0
while not q.empty():
    cur = q.get()
    inque[cur] = False
    for w, nxt in adj[cur]:
        if dis[cur] + w < dis[nxt]:
            dis[nxt] = dis[cur] + w
            if not inque[nxt]:
                inque[nxt] = True
                q.put(nxt)

for i in range(qq):
    d = dis[int(input())]
    print(-1 if d == MX else d)

