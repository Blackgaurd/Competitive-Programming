# UCC Coding Competition '21 P1 - Counterfeit Detection

import sys

t = sys.stdin.readline()[:-1]
print(t.count('2') - t.count('5'))