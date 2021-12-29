# An Animal Contest 4 P1 - Dasher's Digits

n, m = map(int, input().split())
t = input()
arr = list(map(int, input().split()))

mx, ind = 0, -1
for i in range(m):
    if arr[i] >= mx:
        mx = arr[i]
        ind = i

cnt = -1
start = ""
end = ""
for char in t:
    if char == "0":
        cnt += 1
    elif cnt >= ind:
        start += char
    else:
        end += char

print(start, end, sep="")
