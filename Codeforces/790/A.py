# A. Lucky?

for i in range(int(input())):
    a = input()
    if sum(map(int, a[:3])) == sum(map(int, a[3:])):
        print("YES")
    else:
        print("NO")
