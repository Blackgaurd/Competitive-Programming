// Coding Spree

#include <stdio.h>

#include <algorithm>

int n, t;
long long dp[1003];
int main() {
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++) {
        int v, h;
        scanf("%d%d", &v, &h);
        for (int j = t; j >= h; j--) {
            dp[j] = std::max(dp[j], v + dp[j - h]);
        }
    }
    printf("%lld\n", dp[t]);

    return 0;
}