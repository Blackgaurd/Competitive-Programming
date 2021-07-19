# CCC '13 S4 - Who is Taller?
# submit in pypy

import sys

input = sys.stdin.readline

classmates, n = map(int, input().split())
graph = {}
for i in range(n):
    x, y = map(int, input().split())
    if x not in graph:
        graph[x] = [y]
    else:
        graph[x].append(y)
a, b = map(int, input().split())
queue = []


def bfs(graph, node, t):
    vis = {node}
    queue.append(node)
    while queue:
        s = queue.pop(0)
        if s == t:
            return True
        if s in graph:
            for neighbour in graph[s]:
                if neighbour not in vis:
                    vis.add(neighbour)
                    queue.append(neighbour)
    return False


if bfs(graph, a, b):
    print("yes")
elif bfs(graph, b, a):
    print("no")
else:
    print("unknown")
