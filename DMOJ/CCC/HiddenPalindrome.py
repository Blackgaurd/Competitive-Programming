# CCC '16 J3 - Hidden Palindrome

from difflib import SequenceMatcher

word = input()
rev = word[::-1]
pal = SequenceMatcher(None, word, rev).find_longest_match(0, len(word), 0, len(rev))
print(pal.size)