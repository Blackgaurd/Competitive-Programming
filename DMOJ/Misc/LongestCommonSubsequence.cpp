// Longest Common Subsequence

#include <stdio.h>
#define max(a, b) (a > b ? a : b)

int n, m, a[1001], b[1001], dp[1001][1001];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j] == b[i]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    printf("%d\n", dp[m][n]);

    return 0;
}