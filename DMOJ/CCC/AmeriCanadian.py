# CCC '02 J2 - AmeriCanadian

import sys

vow = lambda char: char in 'aeiouy'
for word in sys.stdin:
    word = word[:-1]
    if word == 'quit!':
        break
    if len(word) < 4:
        print(word)
    elif word[-2:] == 'or' and not vow(word[-3]):
        print(word[:-2] + 'our')
    else:
        print(word)