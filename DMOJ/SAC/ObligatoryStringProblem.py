# SAC '22 Code Challenge 4 P2 - Obligatory String Problem

from string import ascii_lowercase

k = int(input())
c = input()

dis = lambda a, b: sum(
    min(
        abs(ord(a[i]) - ord(b[i])),
        ord(a[i]) - ord("a") + ord("z") - ord(b[i]) + 1,
    )
    for i in range(4)
)


for i in ascii_lowercase:
    for j in ascii_lowercase:
        for k_ in ascii_lowercase:
            for l in ascii_lowercase:
                b = i + j + k_ + l
                if dis(c, b) <= k:
                    print(b)
