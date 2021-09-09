# DMOPC '21 Contest 1 P1 - Partial Game

n = int(input())
duke = 0
alice = 0
for i in map(int, input().split()):
    if i % 2 == 0:
        duke += i / 2
    else:
        alice += i // 2 + 1

print("Duke" if duke > alice else "Alice")