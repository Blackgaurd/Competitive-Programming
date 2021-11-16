# CCC '08 J4 - From Prefix to Postfix

import sys

while True:
    operation = sys.stdin.readline()
    if operation != "0\n":
        operation = operation.split()
        i = len(operation)
        for index in range(i - 1, -1, -1):
            if operation[index] in "+-":
                operation[index] = (
                    operation[index + 1]
                    + " "
                    + operation[index + 2]
                    + " "
                    + operation[index]
                )
                operation.pop(index + 2)
                operation.pop(index + 1)
    else:
        break
    print(*operation)
