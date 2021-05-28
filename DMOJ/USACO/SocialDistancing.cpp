// USACO 2020 Open Silver P1 - Social Distancing

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

int n, m;
vector<pair<ll,ll>> arr;

bool range(ll a, ll x , ll y){
    return (a>=x && a<=y);
}

bool check(int x){ // x = seperate dis
    int cnt = 1;
    ll prev = arr[0].first, ind = 0;
    while (true){
        if (ind+1==m) break;
        if (range(prev+x, arr[ind].first, arr[ind].second)){
            prev+=x; cnt++;
        } 
        else if (range(prev+x, arr[ind].second, arr[ind+1].first)){
            if (arr[ind+1].first>=prev+x){
                prev = arr[ind+1].first; cnt++;
            }
            ind++;
        } else ind++;
    }
    return cnt>=n;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i=0; i<m; i++){
        ll a, b; cin >> a >> b;
        arr.pb(make_pair(a,b));
    }
    ll lo = 1, hi = arr[m-1].second-arr[0].first, ans = 0;
    sort(arr.begin(), arr.end());
    while (lo<=hi){
        ll mid = (lo+hi)/2;
        if (check(mid)){ans=mid; lo=mid+1;}
        else hi=mid-1;
    }
    cout << ans << nl;

    return 0;
}