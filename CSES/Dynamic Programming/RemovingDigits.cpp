// Removing Digits

#include <bits/stdc++.h>
using namespace std;

const int MM = 1e6 + 3;
int dp[MM];
int solve(int x) {
    if (x < 0)
        return INT_MAX - 1;
    if (dp[x] != INT_MAX)
        return dp[x];

    int digit = x;
    while (digit) {
        if (digit % 10)
            dp[x] = min(dp[x], solve(x - digit % 10) + 1);
        digit /= 10;
    }
    return dp[x];
}
int main() {
    int x;
    scanf("%d", &x);
    for (int i = 1; i <= x; i++)
        dp[i] = INT_MAX;
    printf("%d\n", solve(x));
}