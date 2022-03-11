# CCC '17 S1 - Sum Game

import sys

games = int(sys.stdin.readline())
team1 = list(map(int, sys.stdin.readline().split()))
team2 = list(map(int, sys.stdin.readline().split()))
sum1 = sum(team1)
sum2 = sum(team2)

for i in range(games, 0, -1):
    if sum1 == sum2:
        print(i)
        break
    else:
        sum1 -= team1.pop()
        sum2 -= team2.pop()
else:
    print(0)
