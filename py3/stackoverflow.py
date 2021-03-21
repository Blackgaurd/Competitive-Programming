import math
n = int(input("Enter a value for n: "))
k = int(input("Enter a value for k: "))

if k == n:
    print(1)
elif k == 1:
    print(n)
elif k > n:
    print(0)
else:
    a = math.factorial(n)
    b = math.factorial(k)
    c = math.factorial(n-k)
    div = a // (b * c)
    with open("output.txt", "a") as f:
        f.write(str(div))