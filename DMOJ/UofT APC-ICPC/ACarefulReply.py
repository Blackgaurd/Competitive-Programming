# A Careful Reply

for i in range(int(input())):
    cnt = input().count("<3") + 1
    out = "<3 " * cnt
    print(out[:-1])