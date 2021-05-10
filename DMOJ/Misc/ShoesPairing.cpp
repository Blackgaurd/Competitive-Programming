// Shoes Pairing

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define ms memset
#define pb push_back
#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll, ll>;
using qi = queue<int>;
using qpii = queue<pii>;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    int l[n+1], r[n], pre[n], suf[n];
    for (int i=0; i<=n; i++) cin >> l[i];
    for (int i=0; i<n; i++) cin >> r[i];
    pre[0] = l[0]-r[0];
    for (int i=1; i<n; i++) pre[i] = max(pre[i-1], l[i]-r[i]);
    suf[n-1] = l[n]-r[n-1];
    for (int i=n-2; i>=0; i--) suf[i] = max(suf[i+1], l[i+1]-r[i]);
    for (auto i: pre) cout << i << " ";
    cout << nl;
    for (auto i: suf) cout << i << " ";
    cout << nl;
    for (int i=0; i<n; i++) cout << max(pre[i], suf[i]) << " ";
    return 0;
}