# CCC '07 J3 - Deal or No Deal Calculator

arr = [0, 100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000]
ttl = sum(arr)
n = int(input())
for i in range(n):
    ttl -= arr[int(input())]

print("deal" if ttl // (10-n) < int(input()) else "no deal")
