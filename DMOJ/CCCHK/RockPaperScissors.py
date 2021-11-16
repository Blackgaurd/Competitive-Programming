# CCCHK '15 J1 - Rock-paper-scissors

n = int(input())
a = input().split()
b = input().split()
awins = 0
bwins = 0
for x in range(n):
    if a[x] == "rock":
        if b[x] == "paper":
            bwins += 1
        elif b[x] == "scissors":
            awins += 1
    elif a[x] == "paper":
        if b[x] == "scissors":
            bwins += 1
        elif b[x] == "rock":
            awins += 1
    elif a[x] == "scissors":
        if b[x] == "rock":
            bwins += 1
        elif b[x] == "paper":
            awins += 1

print(awins, bwins)
