# Digit Queries


def digits_before(k):
    digits = len(str(k))
    b = sum(9 * pow(10, i - 1) * i for i in range(1, digits))
    a = (k - pow(10, digits - 1)) * digits
    return a + b


def solve(k):
    lo, hi = 1, int(1e18)
    while lo <= hi:
        mid = (lo + hi) // 2
        before = digits_before(mid)
        if before + 1 <= k <= before + len(str(mid)):
            ind = k - before - 1
            print(str(mid)[ind])
            break
        elif k <= before:
            hi = mid - 1
        else:
            lo = mid + 1


for q in range(int(input())):
    solve(int(input()))
