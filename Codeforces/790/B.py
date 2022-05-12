# B. Equal Candies

for t in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    mn = min(arr)
    print(sum(x - mn for x in arr))
