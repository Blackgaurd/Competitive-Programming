# BlueBook - Digits and Sums

for i in range(*map(int, input().split())):
    if sum(map(lambda x: int(x) ** 3, str(i))) == i:
        print(i)
else:
    i += 1
    if sum(map(lambda x: int(x) ** 3, str(i))) == i:
        print(i)
