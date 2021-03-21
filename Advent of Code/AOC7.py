import sys
import re

contents = {}
totals = {}
sol = {}
ans = 0
vis = set()


def solve(cur):
    global ans
    #print(cur)
    if sol[cur] == 0:
        sol[cur]=1
        return 1
    for nxt in contents[cur]:
        solve(nxt[1])
        sol[cur] += nxt[0] * sol[nxt[1]]
    return sol[cur]




while 1:
    t = input()
    if t == "0": break
    # t = ''.join(filter(lambda x: not x.isdigit(), t))
    t = t.split("contain")
    t[1] = t[1].split(",")
    t[0] = t[0].strip()
    if t[0][-1] == 's': t[0] = t[0][:-1]
    for i in range(len(t[1])):
        t[1][i] = t[1][i].strip()
        while t[1][i][-1] == 's' or t[1][i][-1] == '.':
            t[1][i] = t[1][i][:-1]
        t[1][i] = t[1][i].split(" ", 1)
        t[1][i][1].strip()
        if t[1][i][0] == "no":
            t[1][i][0] = 0
        else:
            t[1][i][0] = int(t[1][i][0])
    if t[0] not in sol: sol[t[0]] = 0
    if t[0] not in totals: totals[t[0]] = 0
    for i in range(len(t[1])):
        totals[t[0]] += t[1][i][0]
    if t[0] not in contents:
        contents[t[0]] = [i for i in t[1]]
    # print(t)
#print(contents)
#print(totals)

"""
q = ["shiny gold bag"]
vis = set()
while q:
    cur = q.pop(0)
    if cur not in bag:
        continue
    for nxt in bag[cur]:
        if nxt not in vis:
            vis.add(nxt)
            q.append(nxt)

print(vis)
print(len(vis))
"""

solve("shiny gold bag")
solve("shiny gold bag")
for i in sol:
    if sol[i]>=1:
        print(i, sol[i])
for i in sol:
    if sol[i]>0:
        ans+=sol[i]
print(ans)
