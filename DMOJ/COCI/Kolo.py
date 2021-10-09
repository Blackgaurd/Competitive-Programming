# COCI '10 Contest 7 #2 Kolo


def main():
    n, k = map(int, input().split())
    seen = set()

    arr = ["?" for i in range(n)]
    ptr = 0
    for i in range(k):
        x, s = input().split()
        x = int(x)
        ptr = (ptr - x % n + n) % n
        if arr[ptr] == "?":
            if s in seen:
                print("!")
                return
            seen.add(s)
            arr[ptr] = s
        elif arr[ptr] != s:
            print("!")
            return
    print(*arr[ptr:], *arr[:ptr], sep="")


main()
