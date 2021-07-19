# CCC '14 S3 - The Geneva Confection

for _ in range(int(input())):
    branch = []
    lake = []
    needed = 1
    mountain = [int(input()) for i in range(int(input()))]
    while 1:
        if mountain and mountain[-1] == needed:
            lake.append(mountain.pop())
            needed += 1
        elif branch and branch[-1] == needed:
            lake.append(branch.pop())
            needed += 1
        elif mountain:
            branch.append(mountain.pop())
        elif branch:
            print("N")
            break
        else:
            print("Y")
            break
