# USACO 2019 February Bronze P1 - Sleepy Cow Herding

arr = list(map(int, input().split()))
arr.sort()

# minimum
if arr[1] - arr[0] == 2 or arr[2] - arr[1] == 2:
    print(1)
elif arr[2] - arr[0] == 2:
    print(0)
else:
    print(2)

# maximum
print(max(arr[1] - arr[0], arr[2] - arr[1]) - 1)
