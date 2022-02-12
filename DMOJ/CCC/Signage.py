# CCC '09 J4 - Signage

words = "WELCOME TO CCC GOOD LUCK TODAY".split()

w = int(input())
out = []
cur = []

for word in words:
    if sum(map(len, cur)) + len(cur) + len(word) > w:
        out.append([*cur])
        cur.clear()
    cur.append(word)

if cur:
    out.append(cur)

for line in out:
    periods = w - sum(map(len, line))
    if len(line) == 1:
        line[0] += "." * periods
    else:
        ptr = 0
        for i in range(periods):
            line[ptr] += "."
            ptr += 1
            if ptr == len(line) - 1:
                ptr = 0

    print("".join(line))