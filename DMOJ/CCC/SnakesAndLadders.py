# CCC '03 S1 - Snakes and Ladders

pos = 1
while pos != 100:
    roll = int(input())
    if roll == 0:
        print("You Quit!")
        break
    if pos + roll > 100:
        print("You are now on square", pos)
        continue
    pos += roll
    if pos == 9:
        pos = 34
    elif pos == 40:
        pos = 64
    elif pos == 67:
        pos = 86
    elif pos == 99:
        pos = 77
    elif pos == 90:
        pos = 48
    elif pos == 54:
        pos = 19
    print("You are now on square", pos)
else:
    print("You Win!")
