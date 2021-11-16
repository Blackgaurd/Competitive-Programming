# COCI '16 Contest 3 #1 Imena

import re
from string import ascii_uppercase as UP, ascii_lowercase as LOW

def match(word):
    if word[0] not in UP:
        return False
    return all(char in LOW for char in word[1:])

n = int(input())
for s in re.split("[.!?]", input())[:-1]:
    cnt = sum(1 for word in s.split() if match(word))
    print(cnt)