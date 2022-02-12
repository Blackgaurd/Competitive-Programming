# Mock CCC '22 Contest 2 J3 - Figure Skating Fun

n = int(input())
arr = list(map(int, input().split()))
ttl = sum(arr)

left = 0
for i in range(n):
    left += arr[i]
    ttl -= arr[i]
    if left == ttl:
        print(i + 1)
        break
else:
    print("Andrew is sad.")
