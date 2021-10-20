// Lexicographically Least Substring (Hard)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e6 + 3, MOD = 1e9 + 7, base = 131;
string t;
int k, n, ans = 1;  // ans = starting index of least substr (1-indexed)
ll hsh[MM], p[MM];
void build() {
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = (p[i - 1] * base) % MOD;
        hsh[i] = (hsh[i - 1] * base + t[i - 1]) % MOD;
    }
}
ll sub_hash(int l, int r) {
    return (hsh[r] - hsh[l - 1] * p[r - l + 1] % MOD + MOD) % MOD;
}
bool less_than(int s1, int s2) {
    // find longest substring that match
    int lo = 0, hi = k - 1, ans = -1;
    while (lo <= hi) {
        int len = (lo + hi) / 2;
        if (sub_hash(s1, s1 + len) == sub_hash(s2, s2 + len)) {
            lo = len + 1;
            ans = len;
        } else {
            hi = len - 1;
        }
    }
    if (ans == k - 1) return false;    // two substrings are the same
    return t[s1 + ans] < t[s2 + ans];  // compare next character
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t >> k;
    n = t.size();
    build();
    for (int start = 1; start + k - 1 <= n; start++) {
        if (less_than(start, ans)) ans = start;
    }
    cout << t.substr(ans - 1, k) << '\n';

    return 0;
}