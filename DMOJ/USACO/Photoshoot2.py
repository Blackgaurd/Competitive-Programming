# USACO 2022 February Bronze P2 - Photoshoot 2

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
pos_b = [0 for i in range(n + 1)]
for i in range(n):
    pos_b[b[i]] = i + 1
a = [pos_b[x] for x in a]
mx = 0
ans = 0
for i in a:
    if i > mx:
        mx = i
    else:
        ans += 1
print(ans)

"""
5 1 3 2 4
4 5 2 1 3

pos_b: 4 3 5 1 2
a_new: 2 4 5 3 1
"""
