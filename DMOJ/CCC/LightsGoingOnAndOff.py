# CCC '09 S2 - Lights Going On and Off

lights = [int(i.replace(' ', ''), 2) for i in __import__('sys').stdin.readlines()[2:]]

combs = set(())
cur = 0
for i in range(len(lights)-2, -1, -1):
    cur ^= lights[i]
    combs.add(lights[-1]^cur)

combs.add(lights[-1])
print(len(combs))