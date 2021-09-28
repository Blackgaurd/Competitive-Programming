from itertools import count, islice


def p(n):
    return all(n % i for i in islice(count(2), int(n ** 0.5 - 1)))


a = [i for i in range(3, int(input()), 2) if p(i)]+[0]
print(2)
for i in range(len(a)-1):
    if(a[i] - 2 == a[i - 1])or(a[i] + 2 == a[i + 1]):
        print(str(a[i])+"*")
    else:
        print(a[i])
