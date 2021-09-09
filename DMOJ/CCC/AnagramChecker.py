# CCC '07 J4 - Anagram Checker

from collections import Counter

print("Is an anagram." if Counter(input().replace(' ', '')) == Counter(input().replace(' ', '')) else "Is not an anagram.")