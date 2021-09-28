// Splitting A Sequence

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

const int MM = 1e5 + 5;
int n, m, arr[MM], lo = 0, hi = 0;
ll ans = 0;
bool check(ll x) {
    int cnt = 1;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        if (sum + arr[i] <= x)
            sum += arr[i];
        else {
            cnt++;
            sum = arr[i];
        }
    }
    return cnt <= m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        lo = max(lo, arr[i]);
        hi += arr[i];
    }
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid, hi = mid - 1;
        } else
            lo = mid + 1;
    }
    cout << ans;

    return 0;
}