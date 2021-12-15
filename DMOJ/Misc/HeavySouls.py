# Heavy Souls

letters = "abcdefghijklmnopqrst"
missing = {char: [] for char in letters}

n = int(input())
arr = [set(input()) for i in range(n)]
covered = set()
for char in letters:
    cnt = 0
    for word in arr:
        if char in word:
            cnt += 1
        else:
            missing[char].append("".join(word))
    if cnt == 0:
        del missing[char]

ans = 0
for char, words in missing.items():
    added = False
    for word in words:
        if word not in covered:
            added = True
            covered.add(word)
    if added:
        ans += 1

print(ans)