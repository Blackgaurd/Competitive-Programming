# CCC '10 J1 - What is n, Daddy?

n = int(input())

if n in {1, 9, 10}:
    print(1)
elif n in {2, 3, 7, 8}:
    print(2)
else:
    print(3)
