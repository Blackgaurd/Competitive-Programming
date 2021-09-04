# DWITE '09 R2 #2 - Mini DWITE

for _ in range(5):
    nums = [sum(map(int, input().split())) for i in range(5)]
    ans = sum(1 for i in range(5) if int(input()) == nums[i])
    print(ans)