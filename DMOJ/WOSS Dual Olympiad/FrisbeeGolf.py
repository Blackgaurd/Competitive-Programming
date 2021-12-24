# WOSS Dual Olympiad 2021 J3: Frisbee Golf

a = int(input())
arr = [0 for i in range(7)]
arr[-1], a = divmod(a, 1000)
arr[-2], a = divmod(a, 500)
arr[-3], a = divmod(a, 100)
arr[-4], a = divmod(a, 50)
arr[-5], a = divmod(a, 10)
arr[-6], a = divmod(a, 5)
arr[-7] = a
print(*arr)
