# CCC '02 S1 - The Students' Council Breakfast

pink = int(input())
green = int(input())
red = int(input())
orange = int(input())
ttl = int(input())
ans = set()
mn = int(1e9)


def solve(p, g, r, o):
    s = p * pink + g * green + r * red + o * orange
    if s > ttl:
        return
    if s == ttl:
        ans.add((p, g, r, o))
        return
    solve(p + 1, g, r, o)
    solve(p, g + 1, r, o)
    solve(p, g, r + 1, o)
    solve(p, g, r, o + 1)


solve(0, 0, 0, 0)

for p, g, r, o in ans:
    print(f"# of PINK is {p} # of GREEN is {g} # of RED is {r} # of ORANGE is {o}")
    mn = min(mn, sum((p, g, r, o)))

print(f"Total combinations is {len(ans)}.")
print(f"Minimum number of tickets to print is {mn}.")
