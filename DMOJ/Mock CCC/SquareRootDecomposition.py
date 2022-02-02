# Mock CCC '22 Contest 1 J1 - Square Root Decomposition

n = int(input())
i = int(input())
j = int(input())

a = abs(i * i - n)
b = abs(j * j - n)
if a < b:
    print(1)
else:
    print(2)
