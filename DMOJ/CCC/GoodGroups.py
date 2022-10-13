# CCC '22 S2 - Good Groups

x = int(input())
same_group = []
for i in range(x):
    same_group.append(input().split())

y = int(input())
diff_group = []
for i in range(y):
    diff_group.append(input().split())

g = int(input())
group = {}
for i in range(g):
    names = input().split()
    for name in names:
        group[name] = i

violations = 0
for a, b in same_group:
    if group[a] != group[b]:
        violations += 1

for a, b in diff_group:
    if group[a] == group[b]:
        violations += 1

print(violations)
