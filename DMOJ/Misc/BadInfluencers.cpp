// Bad Influencers

#include <bits/stdc++.h>
using namespace std;
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on
typedef long long ll;

const int MM = 1e5 + 3;
int n;
vector<int> state;
vector<int> adj[MM];
unordered_map<ll, int> dp;
ll toggle(ll state, int ind) {
    for (int nxt : adj[ind]) {
        state ^= (1LL << nxt);
    }
    return state;
}
int solve(ll state) {
    if (dp.find(state) != dp.end()) return dp[state];
    int ret = INT_MAX;
    for (int i = 1; i <= n; i++) {
        ret = min(ret, 1 + solve(toggle(state, i)));
    }
    dp[state] = ret;
    return ret;
}
int main() {
    su(n);
    for (int i = 0, a, b; i < n - 1; i++) {
        su(a);
        su(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll state = 0;
    for (int i = 0, a; i < n; i++){
        su(a);
        state ^= (ll(a) << i);
    }
    printf("%d\n", solve(state));
}