# Longest Sequence

l, r = map(int, input().split())

cnt = 0
while l <= r:
    l *= 2
    cnt += 1
print(cnt)
