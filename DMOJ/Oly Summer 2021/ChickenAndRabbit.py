# Chicken and Rabbit

a, b = map(int, input().split())
if b % 2:
    print("No")
elif a <= b//2 <= 2 * a:
    print("Yes")
else:
    print("No")