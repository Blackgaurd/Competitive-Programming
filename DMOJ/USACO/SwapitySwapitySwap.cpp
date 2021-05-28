// USACO 2020 February Silver P1 - Swapity Swapity Swap

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
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

const int MM = 1e5+5;
int n, m, k, a[102], b[102], nxt[MM], ans[MM];
bool vis[MM]; 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    scan(n); scan(m); scan(k);
    for (int i=1; i<=m; i++){scan(a[i]); scan(b[i]);}
    for (int i=1; i<=n; i++){
        nxt[i] = i;
        for (int j=1; j<=m; j++){
            if (a[j]<=nxt[i] && nxt[i]<=b[j]) nxt[i] = b[j]-(nxt[i]-a[j]);
        }
    }
    for (int i=1; i<=n; i++){
        if (vis[i]) continue;
        int cur = i;
        vi cycle;
        for (; cycle.empty() || cur!=i; cur=nxt[cur]){
            vis[cur] = true;
            cycle.pb(cur);
        }
        int len = cycle.size(), rem = k%len;
        for (int j=0; j<len; j++){
            int pos = cycle[(j+rem)%len];
            ans[pos] = cycle[j];
        }
    }
    for (int i=1; i<=n; i++) cout << ans[i] << nl;

    return 0;
}