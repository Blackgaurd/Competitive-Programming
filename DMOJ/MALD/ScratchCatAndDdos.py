# MALD Contest 1 P1 - Scratch Cat and DDoS

n = int(input())
arr = [input() for i in range(n)]
ans = set()
for i in range(n):
    if "yubo" in arr[i]:
        ans.add(arr[i])
        if i != 0:
            ans.add(arr[i - 1])
        if i != n - 1:
            ans.add(arr[i + 1])

ans = list(ans)
ans.sort()
print(*ans, sep="\n")
