# A. Word Capitalization

a = input()

if 'a' <= a[0] <= 'z':
    print(chr(ord(a[0]) - 32), a[1:], sep='')
else:
    print(a)