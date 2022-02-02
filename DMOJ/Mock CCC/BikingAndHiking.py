# Mock CCC '22 Contest 1 J2 - Biking and Hiking

n, k = map(int, input().split())
t = input()
ans = 0
for c in t:
    if c == "F":
        if k == 0:
            ans += 1
    elif c == "U":
        k -= 1
        if k <= 0:
            k = 0
            ans += 1
    else:
        k += 1

print(ans)
