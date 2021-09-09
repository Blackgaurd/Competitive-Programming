# CCCHK '08 J1 - Best fish


def list_conv(string):
    result = 1
    li = list(string.split(" "))
    for string in range(len(li)):
        li[string] = int(li[string])
    for x in li:
        result *= x
    return result


C = int(input())
C_max = 0
for l in range(C):
    product = list_conv(input())
    if product > C_max:
        C_max = product

N = int(input())
N_max = 0
for l in range(N):
    product = list_conv(input())
    if product > N_max:
        N_max = product

if C_max > N_max:
    print("Casper")
elif C_max < N_max:
    print("Natalie")
else:
    print("Tie")
