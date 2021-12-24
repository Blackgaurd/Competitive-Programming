# COCI '21 Contest 2 #1 Kaučuk

sec = 0
subsec = 0
subsubsec = 0
for i in range(int(input())):
    com, name = input().split()
    if len(com) == 7:
        sec += 1
        subsec = 0
        subsubsec = 0
        print(f"{sec} {name}")
    elif len(com) == 10:
        subsec += 1
        subsubsec = 0
        print(f"{sec}.{subsec} {name}")
    else:
        subsubsec += 1
        print(f"{sec}.{subsec}.{subsubsec} {name}")
