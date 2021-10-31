# COCI '16 Contest 4 #2 Kartomat

arr = [input() for i in range(int(input()))]
word = input()
chars = ["*" for i in range(32)]
for i in arr:
    if i.startswith(word):
        char = ord(i[len(word)]) - ord("A") + 3
        chars[char] = i[len(word)]

chars = "".join(chars)

for i in range(4):
    print(chars[8 * i : 8 * i + 8])
