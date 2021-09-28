// CCC '11 J5 - Unfriend

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on
#define ms memset
#define pb push_back
#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = deque<int>;

int n, cnt[7];
vi adj[7];
void dfs(int u) {
    cnt[u] = 1;
    for (int v : adj[u]) {
        dfs(v);
        cnt[u] *= cnt[v];
    }
    cnt[u]++;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    /*
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u;
        cin >> u;
        adj[u].pb(i);
    }
    dfs(n);
    cout << cnt[n] - 1;

    return 0;
}