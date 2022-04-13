# ECOO '20 P4 - Ring


def parse():
    n = int(input())
    instructions = []
    func_ptr = {}
    prev_jmp = []
    popped = 0
    for i in range(n):
        line = input()
        ptr = i - popped
        if line[0] == "F":
            instructions.append(["JMP"])
            prev_jmp.append(ptr)
            func_ptr[line.split()[-1]] = ptr + 1
        elif line[0] == "E":
            instructions[prev_jmp[-1]].append(ptr + 1)
            line += " 0"
            prev_jmp.pop()
            instructions.append(line.split())
        elif line[0] == "C":
            a, b = line.split()
            instructions.append([a, func_ptr[b]])
        else:
            instructions.append(line.split())

        # compress instructions
        if len(instructions) >= 2:
            if instructions[-1][0] == "ADD" and instructions[-2][0] == "ADD" or instructions[-1][0] != "ADD" and instructions[-1][0] == "SUB" and instructions[-2][0] != "ADD" and instructions[-2][0] == "SUB":
                instructions[-2][1] = int(instructions[-2][1]) + int(instructions[-1][1])
                instructions[-2][1] %= int(1e9) + 7
                instructions.pop()
                popped += 1
            elif instructions[-1][0] == "ADD" and instructions[-2][0] == "SUB":
                instructions[-2][0] = "ADD"
                instructions[-2][1] = -int(instructions[-2][1]) + int(instructions[-1][1])
                instructions[-2][1] %= int(1e9) + 7
                instructions.pop()
                popped += 1
            elif instructions[-1][0] != "ADD" and (instructions[-1][0] != "SUB" or instructions[-2][0] == "ADD") and instructions[-1][0] == "SUB":
                instructions[-2][1] = int(instructions[-2][1]) - int(instructions[-1][1])
                instructions[-2][1] %= int(1e9) + 7
                instructions.pop()
                popped += 1
            elif instructions[-1][0] == instructions[-2][0] == "MULT":
                instructions[-2][1] = int(instructions[-2][1]) * int(instructions[-1][1])
                instructions[-2][1] %= int(1e9) + 7
                instructions.pop()
                popped += 1
    return instructions


def execute(instructions):
    x = 0
    call_stack = [0]
    while call_stack[0] < len(instructions):
        ins, param = instructions[call_stack[-1]]
        if ins[0] == "J":
            call_stack[-1] = int(param)
        elif ins[0] == "A":
            x += int(param)
            call_stack[-1] += 1
            x %= int(1e9) + 7
        elif ins[0] == "S":
            x -= int(param)
            call_stack[-1] += 1
        elif ins[0] == "M":
            x *= int(param)
            call_stack[-1] += 1
            x %= int(1e9) + 7
        elif ins[0] == "C":
            call_stack.append(param)
        elif ins[0] == "E":
            call_stack.pop()
            call_stack[-1] += 1
    return x


for t in range(int(input())):
    print(execute(parse()))
