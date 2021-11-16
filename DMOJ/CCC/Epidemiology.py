# CCC '20 J2 - Epidemiology

import sys
input = sys.stdin.readline

total = int(input())
sick = int(input())
prev = sick
mult = int(input())

i = 0
while sick <= total:
    sick += mult*prev
    prev *= mult
    i += 1

print(i)
