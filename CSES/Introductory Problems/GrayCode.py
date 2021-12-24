# Gray Code


def gen(n):
    if n == 1:
        return ["0", "1"]
    prev = gen(n - 1)
    rev = prev[::-1]
    for i in range(len(prev)):
        prev[i] += "1"
        rev[i] += "0"
    return prev + rev


print(*gen(int(input())), sep="\n")
