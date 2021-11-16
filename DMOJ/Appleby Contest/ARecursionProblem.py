# Appleby Contest '19 P3 - A Recursion Problem

import sys

input = sys.stdin.readline

op = input().replace("(", "").replace(")", "")
op = op.split()[::-1]

stack = []
for x in op:
    if x != "+":
        stack.append(int(x))
    else:
        stack.append(stack.pop() + stack.pop())
print(*stack)
