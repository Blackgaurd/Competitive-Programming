# Palindromic Numbers

l, r = map(int, input().split())

cnt = 0
for i in range(1, 999999 + 1):
    s = str(i)
    a = s + s[::-1]
    b = s + s[::-1][1:]
    if l <= int(a) <= r:
        cnt += 1
    if l <= int(b) <= r:
        cnt += 1
    elif int(b) > r:
        break
print(cnt)
