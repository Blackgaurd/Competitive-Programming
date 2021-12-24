# Missing Number

n = int(input())
ttl = n * (n + 1) // 2
print(ttl - sum(map(int, input().split())))
