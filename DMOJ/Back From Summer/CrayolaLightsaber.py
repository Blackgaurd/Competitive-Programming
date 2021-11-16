# Back From Summer '17 P2: Crayola Lightsaber

from collections import Counter
import sys

input = sys.stdin.readline

n = int(input())
c = Counter(input().split())
print(min(n, (n - (c.most_common()[0][1])) * 2 + 1))
