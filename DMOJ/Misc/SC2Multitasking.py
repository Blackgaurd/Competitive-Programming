# SC2 Multitasking

rows = [
    "qwertyuiop",
    "asdfghjkl",
    "zxcvbnm"
]
dc = {char: i for i in range(3) for char in rows[i]}

ans = 0
for i in range(int(input())):
    t = input()
    for i in range(len(t)-1):
        if dc[t[i]] != dc[t[i+1]]:
            break
    else:
        ans += 1
print(ans)