# Shorest Subsequence


def solve(t):
    ans = ""

    n = len(t)
    seen = set()
    for i in range(n):
        seen.add(t[i])
        if len(seen) == 4:
            ans += t[i]
            seen.clear()

    for ch in "ACTG":
        if ch not in seen:
            ans += ch
            return ans

    return ans


print(solve(input()))
