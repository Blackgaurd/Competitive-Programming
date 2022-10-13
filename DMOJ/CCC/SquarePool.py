# CCC '22 J5 - Square Pool

n = int(input())
t = int(input())
trees = [tuple(map(int, input().split())) for i in range(t)]
trees.append((0, 0))
trees.append((n + 1, n + 1))

ans = 0
for x1, y1 in trees:
    for x2, y2 in trees:
        # make a vertical column
        # from y1 and y2

        # find out which trees are inside this column
        left, right = min(y1, y2), max(y1, y2)
        inside = [0, n + 1]
        for x3, y3 in trees:
            if left < y3 < right:
                inside.append(x3)

        # find maximum possible height
        max_height = 0
        inside.sort()
        for i in range(1, len(inside)):
            top, bottom = inside[i - 1], inside[i]
            max_height = max(max_height, bottom - top - 1)

        max_width = right - left - 1
        side_length = min(max_width, max_height)

        ans = max(ans, side_length)

print(ans)
