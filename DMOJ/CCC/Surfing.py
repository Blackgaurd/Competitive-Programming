# CCC '00 S3 - Surfing

n = int(input())


def tokenize(line):
    bracket = False
    token = ""
    ret = []
    for char in line:
        if char == "<":
            token = ""
            bracket = True
        elif bracket and char == ">":
            ret.append(token)
            bracket = False
        token += char
    return ret


parse_url = lambda token: token[9:-1]

mp = {}
vis = []
adj = [[] for i in range(103)]


def dfs(cur, end):
    if cur == end:
        return True
    vis[cur] = True
    return any(not vis[nxt] and dfs(nxt, end) for nxt in adj[cur])


for i in range(n):
    root = input()
    if root not in mp:
        mp[root] = len(mp)
    while True:
        line = input()
        tokens = tokenize(line)
        for token in tokens:
            if token.startswith("<A"):
                parsed = parse_url(token)
                print(f"Link from {root} to {parsed}")
                if parsed not in mp:
                    mp[parsed] = len(mp)
                adj[mp[root]].append(mp[parsed])
        if tokens and tokens[-1] == "</HTML":
            break

while True:
    start = input()
    if start == "The End":
        break
    end = input()
    vis = [False for i in range(len(mp))]
    if dfs(mp[start], mp[end]):
        print(f"Can surf from {start} to {end}.")
    else:
        print(f"Can't surf from {start} to {end}.")
