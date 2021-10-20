# COCI '13 Contest 5 #1 Lozinka

seen = set()
for i in range(int(input())):
    t = input()
    if t == t[::-1]:
        print(len(t), t[len(t) // 2])
        break
    if not seen or (t not in seen and t[::-1] not in seen):
        seen.add(t)
    else:
        print(len(t), t[len(t) // 2])
        break
