# Bob's Difference Sum

n = int(input())
arr = sorted(map(int, input().split()))

print(sum(arr[i] * (i + i - n + 1) for i in range(n)))