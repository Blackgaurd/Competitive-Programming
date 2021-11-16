# CCC '20 J4 - Cyclic Shifts

line = input()
cycle = input()

for i in range(len(cycle)):
    if cycle in line:
        print('yes')
        break
    cycle = cycle[-1] + cycle[:-1]
else:
    print('no')
