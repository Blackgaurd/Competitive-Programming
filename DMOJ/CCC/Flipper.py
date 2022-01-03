# CCC '19 S1 - Flipper

grid = [["1", "2"], ["3", "4"]]

t = input()
if t.count("H") % 2:
    grid.append(grid.pop(0))
if t.count("V") % 2:
    grid[0].append(grid[0].pop(0))
    grid[1].append(grid[1].pop(0))

print(" ".join(grid[0]))
print(" ".join(grid[1]))
