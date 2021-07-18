# CCC '19 J3 - Cold Compress

import sys

def parse(line):
    ret = ""
    cnt = 0
    for i in range(len(line)-1):
        cnt += 1
        if line[i] != line[i+1]:
            ret += f"{cnt} {line[i]} "
            cnt = 0
    return ret

for i in sys.stdin.readlines()[1:]:
    print(parse(i))
