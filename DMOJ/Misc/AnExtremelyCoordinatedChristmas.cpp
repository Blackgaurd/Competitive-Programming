// 

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ms memset
#define pb push_back
#define nl "\n"
#define mp make_pair
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = deque<int>;

int n, q;
vector<pii> adj[100005];
bool vis[100005];
void dfs(int cur, int dis){

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    /*
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    cin >> n >> q;
    for (int i=0; i<n; i++){
        int a, b, w; cin >> a >> b >> w;
        adj[a].pb(mp(w, b));
        adj[b].pb(mp(w, a));
    }
    for (int i=0; i<q; i++){
        int a; cin >> a;
        dfs(a, 0);
    }

    return 0;
}