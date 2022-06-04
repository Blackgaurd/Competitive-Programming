// Grid 2
// dp array:
// number of paths from (1, 1) to the i-th wall
// that do not go through any other walls

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
typedef long long ll;

const int MN = 1e5 + 3, MD = 3003, MOD = 1e9 + 7;
ll h, w, n, dp[MD];
ll fact[2 * MN], invfact[2 * MN];
vector<pii> walls;
ll qpow(ll a, ll exp) {
    ll ret = 1;
    while (exp > 0) {
        if (exp & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        exp >>= 1;
    }
    return ret;
}
void fermat(int n) {
    fact[0] = invfact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invfact[i] = qpow(fact[i], MOD - 2);
    }
}
ll nck(int a, int b) {
    return (fact[a] * (invfact[b] * invfact[a - b] % MOD)) % MOD;
}
ll path(pii start, pii end) {
    return nck(end.first - start.first + end.second - start.second, end.first - start.first);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w >> n;
    fermat(2 * max(h, w));
    walls.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> walls[i].first >> walls[i].second;
    }
    walls.back() = {h, w};
    sort(walls.begin(), walls.end());

    for (int i = 0; i <= n; i++) {
        ll paths = path({1, 1}, walls[i]);
        for (int j = 0; j < i; j++) {
            if (walls[j].second > walls[i].second) continue;
            paths -= dp[j] * path(walls[j], walls[i]);
            if (paths < 0) paths += (-paths / MOD + 1) * MOD;
        }
        dp[i] = paths % MOD;
    }
    cout << dp[n] << '\n';
}