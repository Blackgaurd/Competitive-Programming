import sys
input = sys.stdin.readline

n = int(input())
for i in range(n):
    print('*'*n + 'x'*n + '*'*n)
for i in range(n):
    print(' '*n + 'xx'*n)
for i in range(n):
    print('*'*n + ' '*n + '*'*n)
