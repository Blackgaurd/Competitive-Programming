# SAC '22 Code Challenge 3 Junior P3 - Normal Probabilities

p = {
    "A": 1.0,
    "B": 0.8,
    "C": 0.6,
    "D": 0.4,
    "E": 0.2,
}
ans = 1
for i in range(int(input())):
    ans *= p[input()]
print(ans)