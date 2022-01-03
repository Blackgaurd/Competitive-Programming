# BSSPC '21 S1 - Lakshy and Palindromic Rectangle


def main():
    n, m = map(int, input().split())
    arr = [list(input()) for i in range(n)]
    for i in range((n - 1) // 2 + 1):
        for j in range((m - 1) // 2 + 1):
            chars = set()
            if arr[i][j] != ".":
                chars.add(arr[i][j])
            if arr[n - 1 - i][j] != ".":
                chars.add(arr[n - 1 - i][j])
            if arr[n - 1 - i][m - 1 - j] != ".":
                chars.add(arr[n - 1 - i][m - 1 - j])
            if arr[i][m - 1 - j] != ".":
                chars.add(arr[i][m - 1 - j])

            if not chars:
                arr[i][j] = "a"
                arr[n - 1 - i][j] = "a"
                arr[n - 1 - i][m - 1 - j] = "a"
                arr[i][m - 1 - j] = "a"
            elif len(chars) == 1:
                char = chars.pop()
                arr[i][j] = char
                arr[n - 1 - i][j] = char
                arr[n - 1 - i][m - 1 - j] = char
                arr[i][m - 1 - j] = char
            else:
                print(-1)
                return

    for row in arr:
        print("".join(row))


main()
