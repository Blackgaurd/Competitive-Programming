// Big Deposits

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#define ms memset
#define pb push_back
#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll, ll>;
using qi = deque<int>;
using qpii = deque<pii>;

ll p, y, t, ans = 0;

bool check(ll x) {
    ll amount = 0;
    for (ll i = 1; i <= y; i++) {
        amount += x;
        amount += amount * p / 100;
        if (amount >= t) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> p >> y >> t;
    ll lo = 1, hi = t;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else
            lo = mid + 1;
    }
    cout << ans;

    return 0;
}