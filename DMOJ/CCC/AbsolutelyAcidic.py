# CCC '12 S3 - Absolutely Acidic

from collections import defaultdict
import sys

input = sys.stdin.readline

n = int(input())
freq = [0] * 1001
for i in range(n):
    freq[int(input())] += 1

rev = defaultdict(lambda: [])

for i in range(1, len(freq)):
    if freq[i]:
        rev[freq[i]].append(i)

arr = list(rev.items())
arr.sort(reverse=True)

if len(arr[0][1]) > 1:
    print(max(arr[0][1]) - min(arr[0][1]))
else:
    a = arr[0][1][0]
    b = max(arr[1][1], key=lambda x: abs(x - a))
    print(abs(a - b))
