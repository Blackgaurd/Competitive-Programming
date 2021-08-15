# CCC '04 J3 - Smile with Similes

a = int(input())
b = int(input())

adj = [input() for i in range(a)]
noun = [input() for i in range(b)]

for i in adj:
    for j in noun:
        print(f"{i} as {j}")
