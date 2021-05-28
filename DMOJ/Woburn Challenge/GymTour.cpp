// WC '18 Contest 3 S2 - Gym Tour

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
using qi = deque<int>;

const int MM = 1e5+3;
int n, k, f, dis[MM], dep[MM], mxdep = 0;
bool gym[MM];
vi adj[MM];
void dfs(int cur, int prev){
    dis[cur] = 0;
    for (int nxt: adj[cur]){
        if (nxt==prev) continue;
        dep[nxt] = dep[cur]+1;
        dfs(nxt, cur);
        if (gym[nxt]){
            dis[cur]+=dis[nxt]+1;
            gym[cur] = true;
        }
    }
    if (gym[cur]) mxdep = max(mxdep, dep[cur]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    /*
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    cin >> n >> k >> f;
    for (int i=1; i<=k; i++){
        int a; cin >> a;
        gym[a] = true;
    }
    for (int i=1; i<n; i++){
        int a, b; cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    dfs(1, 0);
    int without_dragon = 2*dis[1]-mxdep;
    gym[f] = true;
    dfs(1, 0);
    int with_dragon = dis[1];
    cout << min(with_dragon, without_dragon) << nl;

    return 0;
}