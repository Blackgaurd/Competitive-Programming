// COCI '06 Contest 5 #6 Dvaput
// hash collision bruh

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int MM = 2e5 + 3, MOD = 1e9+7, base1 = 131, base2 = 137;
int n;
string t;
ll h1[MM], h2[MM], p1[MM], p2[MM];
hash<ll> hasher;
void build() {
    p1[0] = p2[0] = 1;
    for (int i=1; i<=n; i++){
        h1[i] = (h1[i - 1] * base1 + t[i - 1]) % MOD;
        p1[i] = p1[i - 1] * base1 % MOD;
        h2[i] = (h2[i - 1] * base2 + t[i - 1]) % MOD;
        p2[i] = p2[i - 1] * base2 % MOD;
    }
}
ll sub_hash1(int l, int r) {
    return (h1[r] - h1[l - 1] * p1[r - l + 1]) % MOD;
}
ll sub_hash2(int l, int r) {
    return (h2[r] - h2[l - 1] * p2[r - l + 1]) % MOD;
}
ll merge_hash(int l, int r){
    ll hsh1 = sub_hash1(l, r);
    ll hsh2 = sub_hash2(l, r);
    return hasher(hsh1) ^ hasher(hsh2);
}
bool exists(int len) {
    unordered_set<ll> seen;
    for (int start = 1; start + len - 1 <= n; start++) {
        ll hsh = merge_hash(start, start + len - 1);
        if (!seen.empty() && seen.find(hsh) != seen.end()) return true;
        seen.insert(hsh);
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> t;
    build();
    int lo = 0, hi = n - 1, ans = -1;
    while (lo <= hi) {
        int len = (lo + hi) / 2;
        if (exists(len)) {
            lo = len + 1;
            ans = len;
        } else
            hi = len - 1;
    }
    cout << ans << '\n';

    return 0;
}