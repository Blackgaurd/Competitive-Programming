# partials

n, m = map(int, input().split())
arr = [
    ["Y", "YB", "YBY", "YBYB"],
    ["Y\nB", "YB\nBY", "YBB\nYYB", "YBYB\nYBBY"],
    ["Y\nB\nY", "YB\nBY\nYB", "YBB\nBYB\nBBY", "YBBY\nBYBY\nBBYB"],
    ["Y\nB\nY\nB", "YB\nBY\nBB\nYY", "YBY\nBYB\nBYY\nYBB", "YBBB\nBYBB\nBBYB\nBBBY"]
]
print(arr[n-1][m-1])