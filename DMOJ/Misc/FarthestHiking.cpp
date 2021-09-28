// Farthest Hiking

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

int m, n, u, f, d, cnt = 0;
string p;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> m >> n >> u >> f >> d >> p;
    for (auto c : p) {
        if (c == 'u' || c == 'd')
            m = m - u - d;
        else if (c == 'f')
            m -= f + f;
        // cout << c << " m: " << m << " count: " << cnt << nl;
        if (m < 0) break;
        cnt++;
    }
    cout << cnt;

    return 0;
}