# A. Way Too Long Words

for i in range(int(input())):
    t = input()
    if len(t) > 10:
        print(f"{t[0]}{len(t)-2}{t[-1]}")
    else:
        print(t)
