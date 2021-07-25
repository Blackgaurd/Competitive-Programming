# CCC '01 J2 - Mod Inverse

def mod_inverse(a, m):
    for x in range(1, m):
        if (((a%m) * (x%m)) % m == 1):
            return x
    return -1

x, m = map(int, input().split())
a = mod_inverse(x, m)
print("No such integer exists." if a == -1 else a)