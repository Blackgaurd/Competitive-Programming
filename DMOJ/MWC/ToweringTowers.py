# MWC '15 #2 P2: Towering Towers
# submit in pypy

import sys
input=sys.stdin.readline
n=int(input())
towers=list(map(int,input().split()))

stack, ans=[],[]
output=''
for i in range(n):
    while len(stack)>0 and towers[i]>=stack[-1][0]:
        stack.pop()
    stack.append((towers[i],i))
    if len(stack)>1:
        ans.append(stack[-1][-1]-stack[-2][-1])
    else:
        ans.append(stack[-1][-1])

print(*ans, sep=' ')