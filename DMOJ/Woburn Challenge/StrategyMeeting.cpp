// WC '07 P3 - Strategy Meeting

#include <bits/stdc++.h>

const int MOD = 13371337;
int t, n, a, dp[15][1 << 14];
bool arr[15][15];
int solve(int cur, int mask) {
    if (cur == n - 1) return dp[cur][mask] = 1;
    if (dp[cur][mask] != -1) return dp[cur][mask];
    int &ret = dp[cur][mask];
    ret = 0;
    for (int i = 0; i < n; i++) {
        if (arr[cur][i] && !(mask & (1 << i))) {
            ret += solve(i, mask | (1 << i));
            ret %= MOD;
        }
    }
    return ret;
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a);
                arr[i][j] = a;
            }
        }
        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(0, 1));
    }

    return 0;
}