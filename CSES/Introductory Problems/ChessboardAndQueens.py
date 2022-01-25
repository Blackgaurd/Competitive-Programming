# Chessboard and Queens

from itertools import permutations

arr = [list(input()) for i in range(8)]

ans = 0
for perm in permutations(range(8)):
    # set
    rdag = [0 for i in range(15)]
    ldag = [0 for i in range(15)]
    for i in range(8):
        if arr[i][perm[i]] == "*":
            break
        rdag[i + perm[i]] += 1
        ldag[8 - perm[i] + i - 1] += 1
    # evaluate
    else:
        for i in range(15):
            if rdag[i] > 1 or ldag[i] > 1:
                break
        else:
            ans += 1

print(ans)
