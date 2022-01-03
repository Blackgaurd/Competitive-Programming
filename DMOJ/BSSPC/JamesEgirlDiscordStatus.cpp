// BSSPC '21 S3 - James's Egirl Discord Status

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
vector<ll> psa, dp;
ll ans = 0;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    psa.resize(n + 1);
    dp.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> psa[i];
        psa[i] += psa[i - 1];
        if (i >= k) {
            dp[i] = max({dp[i - k] + psa[i] - psa[i - k], psa[i] - psa[i - k], 0LL});
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}