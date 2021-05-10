# DMOPC '20 Contest 5 P1 - Home Row

a = input()
b = input()
match = 0
for i in range(min(len(a), len(b))):
    if a[i] == b[i]:
        match += 1
    else:
        break

print(len(a) - match + len(b) - match)