# CCC '03 S2 - Poetry

for verse in range(int(input())):
    rhymes = []
    for text in range(4):
        line = input().split()[-1].lower()
        for index, char in enumerate(reversed(line)):
            if char in "aieou":
                rhymes.append(line[-index - 1 :])
                break
        else:
            rhymes.append(line)

    if all(x == rhymes[0] for x in rhymes):
        print("perfect")
    elif rhymes[0] == rhymes[1] and rhymes[2] == rhymes[3]:
        print("even")
    elif rhymes[0] == rhymes[2] and rhymes[1] == rhymes[3]:
        print("cross")
    elif rhymes[0] == rhymes[3] and rhymes[1] == rhymes[2]:
        print("shell")
    else:
        print("free")
