# Bob's Trip Plan

n = int(input())
x = [0] + list(map(int, input().split())) + [0]

arr = [abs(x[i] - x[i - 1]) for i in range(1, len(x))]
psa = [0]
for i in arr:
    psa.append(psa[-1] + i)
post = [0]
for i in arr[::-1]:
    post.append(post[-1] + i)
post.reverse()

for i in range(1, len(x) - 1):
    print(abs(x[i - 1] - x[i + 1]) + psa[i - 1] + post[i + 1])
