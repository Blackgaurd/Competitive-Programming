# Palindrome Reorder

from collections import Counter, deque

a = Counter(input())
out = deque()
if sum(i % 2 for i in a.values()) > 1:
    print("NO SOLUTION")
else:
    for key, val in a.items():
        if val % 2 == 1:
            out.append(key * val)
            break
    for key, val in a.items():
        if val % 2 == 1:
            continue
        out.append(key * (val // 2))
        out.appendleft(key * (val // 2))

print("".join(out))