// CCC '13 S5 - Factor Solitaire

#include <bits/stdc++.h>
using namespace std;

const int MM = 5e6 + 3;  // partials
int n, dp[MM];
int main() {
    cin >> n;
    for (int i = 3; i <= n; i++) dp[i] = INT_MAX;
    dp[2] = 1;
    for (int cur = 2; cur < n; cur++) {
        if (dp[cur] >= cur) {  // all primes
            // cout << cur << ' ' << dp[cur] << '\n';
            continue;
        }
        int add = 1 + cur % 2;
        for (int i = 1; i * i <= cur; i += add) {
            if (cur % i == 0) {
                int a = i, b = cur / i; // a <= b
                if (cur + a <= n)
                    dp[cur + a] = min(dp[cur + a], dp[cur] + b);
                else
                    break;
                if (cur + b <= n) dp[cur + b] = min(dp[cur + b], dp[cur] + a);
            }
        }
    }
    cout << dp[n] << '\n';
}