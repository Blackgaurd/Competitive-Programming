# CCC '05 J4 - Cross Spiral

w = int(input())
h = int(input())

cut_w = int(input())
cut_h = int(input())

steps = int(input())

vis = [[False for i in range(w)] for j in range(h)]
for i in range(cut_h):
    for j in range(cut_w):
        vis[i][j] = True  # top left
        vis[h - i - 1][j] = True  # bottom left
        vis[i][w - j - 1] = True  # top right
        vis[h - i - 1][w - j - 1] = True  # bottom right

# move priority: left, forward, right
def get_left(forward):
    if forward == [0, 1]:
        return [-1, 0]
    if forward == [0, -1]:
        return [1, 0]
    if forward == [1, 0]:
        return [0, 1]
    if forward == [-1, 0]:
        return [0, -1]

def get_right(forward):
    if forward == [0, 1]:
        return [1, 0]
    if forward == [0, -1]:
        return [-1, 0]
    if forward == [1, 0]:
        return [0, -1]
    if forward == [-1, 0]:
        return [0, 1]

forward = [0, 1]
pos = [0, cut_w]
for i in range(steps):
    cy, cx = pos
    vis[cy][cx] = True
    for dy, dx in (get_left(forward), forward, get_right(forward)):
        nx = cx + dx
        ny = cy + dy

        if nx < 0 or nx >= w:
            continue
        if ny < 0 or ny >= h:
            continue
        if vis[ny][nx]:
            continue

        pos = [ny, nx]
        forward = [dy, dx]
        break

print(pos[1] + 1)
print(pos[0] + 1)
