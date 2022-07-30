# New Year's '18 P2 - Mimi and Christmas Cake

from array import array

n = int(input())

MM = int(1e5) + 3
prime = array('i')
for i in range(MM):
    prime.append(True)
prime[1] = False
for i in range(4, MM, 2):
    prime[i] = False
for i in range(3, MM, 2):
    if prime[i]:
        for j in range(i + i, MM, i):
            prime[j] = False
print(sum(prime[i] for i in map(int, input().split())))
