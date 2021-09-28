// String Finding

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e6 + 3, base = 131, MOD = 1e9 + 7;
string a, b;
ll ha[MM], hb[MM], pw[MM];
ll sub_hash(int l, int r) {
    return (ha[r] - ha[l - 1] * pw[r - l + 1] % MOD + MOD) % MOD;
}
int main() {
    cin >> a >> b;
    int n = a.size(), m = b.size();
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        ha[i] = (ha[i - 1] * base + a[i - 1]) % MOD;
        pw[i] = pw[i - 1] * base % MOD;
    }
    for (int i = 1; i <= m; i++) {
        hb[i] = (hb[i - 1] * base + b[i - 1]) % MOD;
    }
    for (int l = 1; l + m - 1 <= n; l++) {
        if (sub_hash(l, l + m - 1) == hb[m]) {
            cout << l - 1 << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';

    return 0;
}