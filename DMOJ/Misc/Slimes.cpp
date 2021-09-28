// Slimes

#include <bits/stdc++.h>
using namespace std;
#define su(x)                                   \
    do {                                        \
        while ((x = getchar()) < '0')           \
            ;                                   \
        for (x -= '0'; '0' <= (_ = getchar());  \
             x = (x << 3) + (x << 1) + _ - '0') \
            ;                                   \
    } while (0)
char _;
typedef long long ll;

const int MM = 403;
ll n, arr[MM], pre[MM], dp[MM][MM];
int main() {
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    su(n);
    for (int i = 1; i <= n; i++) {
        su(arr[i]);
        pre[i] = pre[i - 1] + arr[i];
        dp[i][i] = 0;
    }

    for (int i = 1; i <= n - 1; i++) {
        dp[i][i + 1] = arr[i] + arr[i + 1];
        dp[i][i + 2] = min((arr[i] + arr[i + 1]) * 2 + arr[i + 2],
                           (arr[i + 1] + arr[i + 2]) * 2 + arr[i]);
    }

    for (int len = 3; len <= n - 1; len++) {
        for (int i = 1; i + len <= n; i++) {
            int j = i + len;
            for (int mid = i; mid <= j - 1; mid++) {
                dp[i][j] = min(dp[i][j], dp[i][mid] - pre[i - 1] +
                                             dp[mid + 1][j] + pre[j]);
            }
        }
    }
    printf("%lld\n", dp[1][n]);
    // print();

    return 0;
}
