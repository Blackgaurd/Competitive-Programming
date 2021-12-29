# Exponentiation
# shoutout to python builtin quickpow

for i in range(int(input())):
    print(pow(*map(int, input().split()), int(1e9+7)))