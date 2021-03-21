import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())

row = set(())
col = set(())
for i in range(k):
    r, c = map(int, input().split())
    if r in row:
        row.remove(r)
    else:
        row.add(r)

    if c in col:
        col.remove(c)
    else:
        col.add(c)

print(max(len(row), len(col)))

while len(row) and len(col):
    print(row.pop(), col.pop())

if len(row):
    while len(row):
        print(row.pop(), 1)
elif len(col):
    while len(col):
        print(col.pop(), 1)
