# UCRPC F21 C - Maths of Glory

n, m = map(int, input().split())
t1 = t2 = n

for i in range(1, m + 1):
    a, b, c, d = map(int, input().split())
    t1 -= a * b
    t2 -= c * d
    if t1 <= 0:
        if t2 <= 0:
            print(f"It's a tie at round {i}!")
        else:
            print(f"Team 1 wins at round {i}!")
        break
    elif t2 <= 0:
        print(f"Team 2 wins at round {i}!")
        break
else:
    print("Oh no!")
