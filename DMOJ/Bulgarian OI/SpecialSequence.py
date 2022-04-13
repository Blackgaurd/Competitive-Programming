# Bulgarian OI '09 P5 - Special Sequence

# patterns:
# 70(...0)
# 9(...9)7(...0)
# 2(...0)1(...0)2(...0)
# 3148(...0)
# 3074003(...0)


def gen_generic(num, x):
    for i in range(x):
        yield num
        num *= 10


def gen_997(x):
    for i in range(x):
        yield int(f"9{'9'*i}7")


def gen_20102(x):
    for i in range(x):
        z = "0" * i
        yield int(f"20{z}10{z}2")


arr = list(gen_generic(70, 100))
arr.extend(iter(gen_generic(3148, 100)))
arr.extend(iter(gen_generic(3074003, 100)))
arr.extend(iter(gen_generic(2120, 100)))
for num in gen_997(100):
    arr.extend(iter(gen_generic(num, 200)))
for num in gen_20102(100):
    arr.extend(iter(gen_generic(num, 200)))

arr.sort()
print(arr[int(input()) - 1])
