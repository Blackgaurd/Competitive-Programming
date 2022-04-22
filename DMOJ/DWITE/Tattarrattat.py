# DWITE '11 R1 #5 - Tattarrattat


def solve(s):
    s = " " + s
    dp = [[0 for i in range(len(s) + 1)] for j in range(len(s) + 1)]

    def wpr(start, end):
        if dp[start][end] != 0:
            return dp[start][end]
        if start == end:
            dp[start][end] = 1
        elif start == end - 1:
            dp[start][end] = 2 if s[start] == s[end] else 1
        elif s[start] == s[end]:
            dp[start][end] = max(
                wpr(start + 1, end - 1) + 2, wpr(start + 1, end), wpr(start, end - 1)
            )
        else:
            dp[start][end] = max(wpr(start + 1, end), wpr(start, end - 1))
        return dp[start][end]

    return wpr(1, len(s) - 1)


for i in range(5):
    print(solve(input()))
