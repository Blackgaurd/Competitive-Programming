# CCC '01 J1 - Dressing Up

H = int(input())

for x in range(1, H + 1):
    if x % 2 == 1:
        print("*" * x + " " * (H - x) * 2 + "*" * x)

for x in reversed(range(1, H)):
    if x % 2 == 1:
        print("*" * x + " " * (H - x) * 2 + "*" * x)
