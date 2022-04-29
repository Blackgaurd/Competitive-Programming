# Advertisement
# largest area under histogram

n = int(input())
arr = list(map(int, input().split()))

ans = 0
stk = [0]
for i in range(1, n):
    while stk and arr[stk[-1]] > arr[i]:
        cur = arr[stk.pop()]
        if not stk:
            ans = max(ans, i * cur)
            continue
        ans = max(ans, (i - stk[-1] - 1) * cur)
    stk.append(i)

l = len(stk)
while stk:
    cur = arr[stk.pop()]
    if not stk:
        ans = max(ans, l * cur)
        continue
    ans = max(ans, (l - stk[-1] - 1) * cur)

print(ans)
