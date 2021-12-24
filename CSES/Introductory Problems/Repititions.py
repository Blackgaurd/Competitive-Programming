# Repetitions

t = input()
cur = 1
ttl = 1
for i in range(1, len(t)):
    if t[i] == t[i - 1]:
        cur += 1
    else:
        cur = 1
    ttl = max(ttl, cur)

print(ttl)
