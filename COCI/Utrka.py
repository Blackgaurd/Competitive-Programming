import sys

input = sys.stdin.readline

n = int(input())
sol = input()[:-1]


def XOR(s1, s2):
    out = [chr(ord(a) ^ ord(b)) for a, b in zip(s1, s2)]
    return "".join(out)


for i in range(n-1):
    name = input()[:-1]
    sol = XOR(sol, name)
    print(sol)

print(sol)
