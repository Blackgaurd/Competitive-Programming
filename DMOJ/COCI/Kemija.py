# COCI '08 Contest 3 #2 Kemija

vs = "aeiou"
x = input()
for v in vs:
    x = x.replace(f"{v}p{v}", v)
print(x)
