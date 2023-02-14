# Postfix Notation

op = input().split()

stack = []
for x in op:
    if x not in "+-*/%^":
        stack.append(int(x))
    elif x == "+":
        stack.append(stack.pop() + stack.pop())
    elif x == "-":
        stack.append(stack.pop(-2) - stack.pop())
    elif x == "*":
        stack.append(stack.pop() * stack.pop())
    elif x == "/":
        stack.append(stack.pop(-2) / stack.pop())
    elif x == "%":
        stack.append(stack.pop(-2) % stack.pop())
    elif x == "^":
        stack.append(stack.pop(-2) ** stack.pop())
print(float(*stack))
