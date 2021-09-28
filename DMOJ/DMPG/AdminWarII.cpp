//

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#define ms memset
#define pb push_back
#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = deque<int>;

const int MM = 1e6;
int n;
vi p1, p2;
int solve(vi a, vi b) {
    int ind = 0, cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = ind; j < b.size(); j++) {
            if (a[i] > b[j]) {
                // cout << a[i] << ">" << b[j] << nl;
                cnt++;
                ind = j + 1;
                i++;
            }
            if (j == b.size() - 1) return cnt;
        }
    }
    cout << "hi" << nl;
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        p1.pb(a);
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        p2.pb(a);
    }
    sort(p1.rbegin(), p1.rend());
    sort(p2.rbegin(), p2.rend());
    cout << solve(p1, p2) << nl << solve(p2, p1);

    return 0;
}