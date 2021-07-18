# CCC '11 S1 - English or French?

n = int(input()) # '3' --> 3
t_count = 0
s_count = 0
for _ in range(n):
    sentence = input()
    sentence = sentence.lower()

    t_count += sentence.count('t')
    s_count += sentence.count('s')

if t_count > s_count:
    print("English")
else:
    print("French")