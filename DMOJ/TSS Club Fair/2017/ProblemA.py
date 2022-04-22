# TSS Club Fair 2017 Problem A

from collections import Counter

for t in range(int(input())):
    ans, cnt = Counter(input().split()).most_common(1)[0]
    print(ans if cnt != 1 else "???")
