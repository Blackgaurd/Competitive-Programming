# Mock CCC '22 S1 - Big Mattress Tournament


def solve():
    a, b, c = map(int, input().split())
    if c:
        if c > a:
            return False
        a -= c
        if b % 2 == 1:
            b -= 1
    if a % 2 == 1:
        return False
    if b:
        if b % 2 == 0:
            return True
        else:
            return a > 0
    return True


for i in range(int(input())):
    print("YES" if solve() else "NO")
