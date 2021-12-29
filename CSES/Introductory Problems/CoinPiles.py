# Coin Piles

n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    # 2x + y = a
    # x + 2y = b
    # 2x + 4y = 2b

    # 3y = 2b - a
    y3 = 2 * b - a
    if y3 < 0 or y3 % 3 != 0:
        print("NO")
        continue
    y = y3 // 3

    x2 = a - y
    if x2 < 0 or x2 % 2 != 0:
        print("NO")
        continue
    print("YES")
