# VM7WC '16 #2 Bronze - G

n = int(input())
g = ["GGGGG", "G....", "G..GG", "G...G", "GGGGG"]

for row in g:
    for i in range(n):
        for char in row:
            print(char*n, end="")
        print()