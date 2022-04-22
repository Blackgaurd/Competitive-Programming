# Hungry

n = int(input())
arr = []
for i in range(n):
    a, b = map(int, input().split())
    arr.append((a, b, i + 1))

arr.sort(key=lambda x: x[0])
for i in arr:
    print(end=f"{i[-1]} ")
print()

arr.sort(key=lambda x: x[1])
for i in arr:
    print(end=f"{i[-1]} ")
print()
