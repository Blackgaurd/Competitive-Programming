# CCC '08 J2 - Do the Shuffle

pl = ["A", "B", "C", "D", "E"]

while True:
    b = input()
    n = int(input())
    if b == "1":
        for x in range(n):
            pl.append(pl.pop(0))
    elif b == "2":
        for x in range(n):
            pl.insert(0, pl.pop(-1))
    elif b == "3":
        for x in range(n):
            pl.insert(0, pl.pop(1))
    elif b == "4":
        p = " ".join(pl)
        print(p)
        break
