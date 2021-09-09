# DMOPC '20 Contest 5 P1 - Home Row

a = input()
b = input()
match = 0
for i in range(min(len(a), len(b))):
    if a[i] != b[i]:
        break
    match += 1

print(len(a) - match + len(b) - match)