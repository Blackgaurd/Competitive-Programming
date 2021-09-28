// Pick It

#include <string.h>

#include <algorithm>
#include <cstdio>

#define su(x)                                   \
    do {                                        \
        while ((x = getchar()) < '0')           \
            ;                                   \
        for (x -= '0'; '0' <= (_ = getchar());  \
             x = (x << 3) + (x << 1) + _ - '0') \
            ;                                   \
    } while (0)
char _;

const int MM = 203;
int arr[MM], dp[MM][MM];
int main() {
    while (true) {
        int n;
        su(n);
        if (!n) break;
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) su(arr[i]);
        for (int len = 2; len < n; len++) {
            for (int i = 1; i + len <= n; i++) {
                int j = i + len;
                for (int mid = i + 1; mid < j; mid++) {
                    dp[i][j] = std::max(dp[i][j], arr[i] + arr[mid] + arr[j] +
                                                      dp[i][mid] + dp[mid][j]);
                }
            }
        }
        printf("%d\n", dp[1][n]);
    }

    return 0;
}