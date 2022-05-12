// H1. Maximum Crossings

#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BIT {
    vector<T> bit;
    int n;

    BIT(int size) {
        n = size;
        bit.assign(n, 0);
    }
    void update(int ind, T val) {
        while (ind < n) {
            bit[ind] += val;
            ind |= (ind + 1);
        }
    }
    T query(int r) {
        T ret = 0;
        while (r >= 0) {
            ret += bit[r];
            r = (r & (r + 1)) - 1;
        }
        return ret;
    }
    T query(int l, int r) {
        if (l <= 0) return query(r);
        return query(r) - query(l - 1);
    }
};
int t;
void solve() {
    int n;
    cin >> n;
    BIT<int> bit(n + 1);
    long long ans = 0;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        ans += bit.query(a, n);
        bit.update(a, 1);
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
}