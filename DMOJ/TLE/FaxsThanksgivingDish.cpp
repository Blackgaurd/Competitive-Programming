// TLE '17 Contest 3 P3 - Fax's Thanksgiving Dish

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

int n, m, cnt[300005];
vi adj[300005];
bool vis[300005];
int dfs(int cur){
    vis[cur] = true;
    int mn = INT_MAX;
    for (auto nxt: adj[cur]){
        mn = min(mn, dfs(nxt));
    }
    if (mn!=INT_MAX) return mn+cnt[cur];
    return cnt[cur];
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
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int target, k;
        cin >> target >> k;
        for (int j=1; j<=k; j++){
            int x; cin >> x; 
            adj[target].pb(x);
        }
    }
    for (int i=1; i<=n; i++) cin >> cnt[i];
    cout << dfs(1);

    return 0;
}