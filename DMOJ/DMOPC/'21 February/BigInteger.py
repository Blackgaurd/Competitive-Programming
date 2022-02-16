input()
s = list(input())
for i in range(len(s)-1):
    if s[i] < s[i+1]:
        s[i], s[i+1] = s[i+1], s[i]
        break
print("".join(s))

