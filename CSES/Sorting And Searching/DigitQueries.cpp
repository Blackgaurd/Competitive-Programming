// Digit Queries

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int q;
ll digits[17];
ll before(ll x) {
    int len = to_string(x).size();
    ll ret = digits[len - 1];
    ret += len * (x - pow(10L, len - 1));
    return ret;
}
int solve(ll x) {
    ll lo = 1, hi = LLONG_MAX / 4;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (before(mid) > x) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
        cout << mid << '\n';
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    for (int i = 1; i < 17; i++) {
        digits[i] = digits[i - 1] + pow(10L, i - 1) * 9 * i;
    }
    while (q--) {
        ll n;
        cin >> n;
        cout << solve(n) << '\n';
    }
    cout << before(67) << '\n';
}