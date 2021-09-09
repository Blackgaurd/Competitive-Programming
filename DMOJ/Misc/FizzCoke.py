# Fizz Coke

m, n = map(int, input().split())
nums = []
words = ["" for i in range(n+1)]
ans = [[] for i in range(n+1)]
for i in range(m):
    a, b = input().split()
    nums.append(int(a))
    words[int(a)] = b

nums.sort()

for i in nums:
    for j in range(i, n+1, i):
        ans[j].append(i)

for i in range(1, n+1):
    if len(ans[i]) == 0:
        print(i)
    else:
        for k in ans[i]:
            print(words[k], end="")
        print()