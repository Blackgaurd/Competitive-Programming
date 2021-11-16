# COCI '07 Contest 4 #2 Veci

num = list(map(int, list(input())))

for i in range(len(num) - 1, 0, -1):
    if num[i] > num[i - 1]:
        replace = []
        for digit in num[i - 1 :]:
            if digit > num[i - 1]:
                replace.append(digit)
        smallest = -1 * replace.index(min(replace))
        num[i - 1], num[smallest - 1] = num[smallest - 1], num[i - 1]
        num[i:] = sorted(num[i:])
        print(*num, sep="")
        break
else:
    print(0)
