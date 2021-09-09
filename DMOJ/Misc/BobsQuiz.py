# Bob's Quiz

n, m = map(int, input().split())

for char in input():
    if char == 'x':
        m = max(m-1, 0)
    else:
        m += 1

print(m)