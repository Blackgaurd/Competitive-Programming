# Bob's Expression Evaluation

import sys

input = sys.stdin.readline


def prefix(op):
    stack = []
    for t in op:
        if t not in "+-*/%":
            stack.append(int(t))
        elif t == "+":
            stack.append(stack.pop() + stack.pop())
        elif t == "-":
            stack.append(stack.pop() - stack.pop())
        elif t == "*":
            stack.append(stack.pop() * stack.pop())
        elif t == "/":
            stack.append(int(stack.pop() / stack.pop()))
        elif t == "%":
            stack.append(stack.pop() % stack.pop())
    return stack[0]


def postfix(op):
    stack = []
    for t in op:
        if t not in "+-*/%":
            stack.append(int(t))
        elif t == "+":
            stack.append(stack.pop() + stack.pop())
        elif t == "-":
            stack.append(stack.pop(-2) - stack.pop())
        elif t == "*":
            stack.append(stack.pop() * stack.pop())
        elif t == "/":
            stack.append(int(stack.pop(-2) / stack.pop()))
        elif t == "%":
            stack.append(stack.pop(-2) % stack.pop())
    return stack[0]


for i in range(5):
    op = input().split()
    if op[0] in "+-*/%":
        print(prefix(op[::-1]))
    else:
        print(postfix(op))
