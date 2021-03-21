import sys
input = sys.stdin.readline

count = 0
letters = [0 for i in range(27)]
lines = 0
while (1):
    t = input()
    if t=="0\n": break
    if t=="\n":
        for char in letters:
            if char==lines: count+=1
        lines = 0
        letters = [0 for i in range(26)]
        continue
    for char in t:
        if ord(char)-ord("a")>=0:
            letters[ord(char)-ord("a")]+=1
    lines+=1

print(count)

