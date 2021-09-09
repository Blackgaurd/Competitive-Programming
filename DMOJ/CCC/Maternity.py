# CCC '06 S1 - Maternity

p1, p2 = input(), input()
possible = []
for i in range(0, 10, 2):
    d = min(p1[i:i+2], p2[i:i+2])
    possible.append((not d.islower(), not d.isupper()))

for i in range(int(input())):
    c = input()
    for j in range(5):
        if (c[j].isupper() and not possible[j][0]) or (c[j].islower() and not possible[j][1]):
            print("Not their baby!")
            break
    else:
        print("Possible baby.")