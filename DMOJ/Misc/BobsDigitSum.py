# Bob's Digit Sum

mx = 0
for i in range(int(input())):
    mx = max(mx, sum(map(int, list(input()))))

print(mx)