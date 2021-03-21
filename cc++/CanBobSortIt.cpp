// Can Bob sort it?

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

const int MM = 1e5+5;
int n;
vi a, b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i=0; i<n; i++){
        int x; cin >> x;
        a.pb(x); b.pb(x);
    }
    sort(a.begin(), a.end());
    int swap = 0;
    for (int i=0; i<n; i++){
        //cout << a[i] << " " << b[i] << nl;
        if (a[i]!=b[i]) swap++;
        if (swap==3) break;
    }
    cout << ((swap==0 || swap==2)? "YES":"NO");

    return 0;
}