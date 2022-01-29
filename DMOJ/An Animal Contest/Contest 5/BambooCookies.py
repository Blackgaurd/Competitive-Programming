# An Animal Contest 5 P1 - Bamboo Cookies

n = int(input())
e, o = 0, 0
for i in map(int, input().split()):
    if i % 2:
        e += 1
    else:
        o += 1

print(e // 2 + o // 2)
