// Mock CCC '22 Contest 1 J5 - New Year's Restrictions
// trash problem
// brute force time

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

int n, m;
vector<vector<bool>> adj;
int main() {
    su(n);
    su(m);
    adj.assign(n, vector<bool>(n));
    for (int i = 0, a, b; i < m; i++) {
        su(a);
        su(b);
        a--;
        b--;
        adj[a][b] = adj[b][a] = true;
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> keep;
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                for (int before : keep) {
                    if (adj[before][i]) goto skip;
                }
                keep.push_back(i);
            }
        }
        ans = max(ans, (int)keep.size());
    skip:;
    }
    printf("%d\n", ans);
}