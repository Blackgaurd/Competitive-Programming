# CCC '13 S1 - From 1987 to 2013

y = input()
while True:
    y = str(int(y) + 1)
    if len(y) == len(set(y)):
        print(y)
        break