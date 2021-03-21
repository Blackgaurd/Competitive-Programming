// USACO 2020 January Silver P2 - Loan Repayment

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
using qi = deque<int>;
using qpii = deque<pii>;

ll n, k, m, ans = 0;

bool check(ll x){
    ll g = 0;
    for (ll day=0; day<k;){
        ll y = (n-g)/x;
        if (y<=m){g+=(k-day)*m; break;}
        ll count = min((n-g-y*x)/y+1, k-day);
        g+=count*y; day+=count;
    }
    return g>=n;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> k >> m;
    ll lo = 1, hi = n;
    while (lo<=hi){
        ll mid = (lo+hi)/2;
        if (check(mid)){ans = mid; lo = mid+1;}
        else hi = mid-1;
    }
    cout << ans;

    return 0;
}