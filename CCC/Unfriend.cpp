// CCC '11 J5 - Unfriend

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

int n, cnt[7]; vi adj[7];
void dfs(int u){
    cnt[u]=1;
    for (int v: adj[u]){
        dfs(v);
        cnt[u]*=cnt[v];
    }
    cnt[u]++;
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
    cin >> n;
    for (int i=1; i<n; i++){
        int u; cin >> u;
        adj[u].pb(i);
    }
    dfs(n);
    cout << cnt[n]-1;

    return 0;
}