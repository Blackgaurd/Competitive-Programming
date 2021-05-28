// CCC '03 S5 - Trucking Troubles

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

int c, r, d, ans = INT_MAX, tmp;
vector<pii> adj[10005];
set<int> cities;
priority_queue<pii, vector<pii>> q;
bool vis[10005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    scan(c); scan(r); scan(d);
    for (int i=0; i<r; i++){
        int a, b, w; scan(a); scan(b); scan(w);
        adj[a].pb({b, w}); adj[b].pb({a, w});
    }
    for (int i=0; i<d; i++){
        scan(tmp);
        cities.insert(tmp);
    }
    q.push({ans, tmp});
    //vis[cities[0]] = true;
    while (!q.empty()){
        int weight = q.top().first, cur = q.top().second;
        q.pop();
        if (!d) break;
        if (!vis[cur]){
            ans = min(ans, weight);
            vis[cur] = true;
            if (cities.count(cur)) d--;
            for (auto nxt: adj[cur]){
                q.push({nxt.second, nxt.first});
            }
        }
    }
    cout << ans << nl;

    return 0;
}