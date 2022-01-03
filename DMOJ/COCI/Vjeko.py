# COCI '13 Contest 6 #1 Vjeko

n = int(input())
pattern = input().split("*")
for i in range(n):
    t = input()
    if (
        len(t) >= len(pattern[0]) + len(pattern[1])
        and t.startswith(pattern[0])
        and t.endswith(pattern[1])
    ):
        print("DA")
    else:
        print("NE")
