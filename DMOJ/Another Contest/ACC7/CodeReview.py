import sys
import random
input = sys.stdin.readline

n = int(input())
arr = [i for i in range(1, n+1)]

random.seed(1)
def scramble():
    ret = []
    for l in range(n-1, -1, -1):
        ind = random.randint(0, l)
        arr[l], arr[ind] = arr[ind], arr[l]
        ret.append(arr.pop())

    return ret


while True:
    print(*arr, sep=' ')
    sys.stdout.flush()

    ret = int(input())
    if ret == 0:
        break

    arr = scramble()