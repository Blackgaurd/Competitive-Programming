closest = {
    'a': 'bc',
    'e': 'dfg',
    'i': 'hjkl',
    'o': 'mnpqr',
    'u': 'stvwxyz'
}
vow = lambda char: char in closest
def nxt(char):
    if char == 'z':
        return char
    ret = chr(ord(char)+1)
    if vow(ret):
        return nxt(ret)
    return ret

ans = ""
for char in input():
    if vow(char):
        print(char, end="")
    else:
        print(char, end="")
        for i, value in closest.items():
            if char in value:
                print(i, end="")
                break
        print(nxt(char), end="")