# USACO 2021 January Bronze P3 - Just Stalling

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
a.sort(reverse=True)
b.sort()

ans = 1
for i in a:
    cnt = len(b)
    # too fried to implement binary search
    for j in range(len(b)):
        if i <= b[j]:
            del b[j]
            break
        cnt -= 1
    ans *= cnt

print(ans)

