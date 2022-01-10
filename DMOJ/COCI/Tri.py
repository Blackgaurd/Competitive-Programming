# COCI '07 Contest 5 #1 Tri

a, b, c = map(int, input().split())
ops = [
    (int.__add__, "+"),
    (int.__sub__, "-"),
    (int.__mul__, "*"),
    (int.__floordiv__, "/"),
]
for op, ch in ops:
    if op(a, b) == c:
        print(f"{a}{ch}{b}={c}")
        break
    if op(b, c) == a:
        print(f"{a}={b}{ch}{c}")
        break
