# DMOPC '19 Contest 1 P2 - Good Writing

base = "Good writing is good writing is good writing."
pre = "Good writing is good "
mid = " writing is good "
suf = " is good writing."

f = [len(base)]
for i in range(1, 30):
    f.append(len(pre) + f[i - 1] + len(mid) + f[i - 1] + len(suf))


def solve(lvl: int, ind: int) -> str:
    if lvl == 0:
        return base[ind]

    cur_size = len(pre)
    if ind < cur_size:
        return pre[ind]

    if ind < cur_size + f[lvl - 1]:
        return solve(lvl - 1, ind - cur_size)
    cur_size += f[lvl - 1]

    if ind < cur_size + len(mid):
        return mid[ind - cur_size]
    cur_size += len(mid)

    if ind < cur_size + f[lvl - 1]:
        return solve(lvl - 1, ind - cur_size)
    cur_size += f[lvl - 1]

    if ind < cur_size + len(suf):
        return suf[ind - cur_size]

    return "."


for i in range(int(input())):
    n, k = map(int, input().split())
    print(solve(n, k - 1))
