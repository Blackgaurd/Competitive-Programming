local stdin, input, print = io.stdin, io.stdin.read, io.write

local n, d, q, l, t = input(stdin, "*n", "*n", "*n", "*n", "*n")

print(n * 5 + d * 10 + q * 25 + l * 100 + t * 200, "\n")