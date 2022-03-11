# USACO 2022 February Bronze P3 - Blocks

from itertools import permutations

n = int(input())
a = list(set(input()))
b = list(set(input()))
c = list(set(input()))
d = list(set(input()))
words = [input() for i in range(n)]
exist = set(words)

for i in a:
    for j in b:
        for k in c:
            for l in d:
                cur = i + j + k + l
                for perm in permutations(cur, 4):
                    word = "".join(perm)
                    for ln in range(3):
                        if word in exist:
                            exist.remove(word)
                        word = word[:-1]

for word in words:
    print("NO" if word in exist else "YES")
