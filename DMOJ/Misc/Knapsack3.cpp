// Knapsack 3

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
ll dp[5003];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int num, cost, val;
        scanf("%d%d%d", &num, &cost, &val);
        for (int k = 1; k <= num; k *= 2) {
            ll w = (ll)k * cost, v = (ll)k * val;
            for (int j = 5000; j >= w; j--) {
                dp[j] = max(dp[j], dp[j - w] + v);
            }
            num -= k;
        }
        if (num) {
            ll w = (ll)num * cost, v = (ll)num * val;
            for (int j = 5000; j >= w; j--) {
                dp[j] = max(dp[j], dp[j - w] + v);
            }
        }
    }
    ll ans = LLONG_MIN;
    for (int i = 1; i <= m; i++) {
        int cap, fuel;
        scanf("%d%d", &cap, &fuel);
        ans = max(ans, dp[cap] - fuel);
    }
    printf("%lld\n", ans);

    return 0;
}