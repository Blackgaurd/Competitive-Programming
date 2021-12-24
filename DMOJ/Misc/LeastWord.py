# Least Word

n, l = map(int, input().split())
arr = []
for i in range(n):
    cur = input()
    arr.append(min(cur, cur[::-1]))
arr.sort()
print("".join(arr))
