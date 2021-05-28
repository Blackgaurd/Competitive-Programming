import sys

lo = 1
hi = int(2e9)

while True:
    mid = (lo + hi) // 2
    print(mid)
    sys.stdout.flush()
    res = sys.stdin.readline()
    if res[0] == 'F':
        hi = mid - 1
    elif res[0] == 'S':
        lo = mid + 1
    else:
        break