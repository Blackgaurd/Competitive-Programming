# Adding Reversed Numbers

for i in range(int(input())):
    a, b = map(int, "".join(reversed(input())).split())
    print("".join(reversed(str(a+b))).lstrip('0'))