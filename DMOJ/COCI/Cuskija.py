# COCI '08 Contest 6 #4 Cuskija

n = int(input())
m0 = []
m12 = []
for i in map(int, input().split()):
    if i % 3 == 0:
        m0.append(i)
    else:
        m12.append(i)

if abs(len(m0) - len( m12)) > 1:
    if len(m0) > len(m12):
        print("impossible")
    else:
        m12.sort(key=lambda x: x%3)
        ind = sum(i % 3 == 1 for i in m12)
        arr = [-1 for i in range(2 * len(m12) - 1)]
        for i in range(len(m12)):
            arr[i * 2] = m12[i]
        arr[ind * 2 - 1] = m0.pop()
        for i in arr:
            if i == -1:
                if m0:
                    print(end=f"{m0.pop()} ")
            else:
                print(end=f"{i} ")
elif len(m0) > len(m12):
    for a, b in zip(m0, m12):
        print(end=f"{a} {b} ")
    print(m0[-1])
else:
    for a, b in zip(m12, m0):
        print(end=f"{a} {b} ")
    print(m12[-1])