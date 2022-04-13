# Good Number


def gen1(l):
    for i in range(1, 10):
        yield int(str(i) * l)


def gen2(l):
    for i in range(1, 10):
        yield i * 10 ** (l - 1)
    for i in range(1, 10):
        base = [str(i) for _ in range(l)]
        for ind in range(l):
            for j in range(ind == 0, 10):
                base[ind] = str(j)
                yield int("".join(base))
                base[ind] = str(i)
    yield 10 ** l


a, k = input(), input()
l = len(a)
a = int(a)
ans = int(1e18)
for i in (gen1 if k == "0" else gen2)(l):
    if i < a:
        continue
    ans = min(ans, i)

print(ans)
