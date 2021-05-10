// A Noisy Class

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

const int MM = 10005;
int n, m, in[MM], cnt = 0;
vi adj[MM];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        in[b]++; adj[a].pb(b);
    }

    qi q;
    for (int i=1; i<=n; i++){
        if (in[i]==0) q.pb(i);
    }
    while (!q.empty()){
        int cur = q.front();
        q.pop_front();
        cnt++;
        for (auto nxt: adj[cur]){
            in[nxt]--;
            if (in[nxt]<=0) q.pb(nxt);
        }
    }
    for (int i=1; i<=n; i++) cout << in[i] << " ";
    cout << nl;
    for (int i=1; i<=n; i++){
        if (in[i]>0) {cout << 'N'; return 0;}
    }
    cout << 'Y';
    

    return 0;
}