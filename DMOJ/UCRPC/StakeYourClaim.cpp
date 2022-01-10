// UCRPC F21 D - Stake Your Claim

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

const int MM = 2e3 + 3;
int n, m, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
bool vis[MM][MM];
int dfs(int i, int j) {
    int ret = (i & 1 || j & 1 ? 0 : 1);
    vis[i][j] = true;
    for (int d = 0; d < 4; d++) {
        if (!vis[i + dx[d]][j + dy[d]])
            ret += dfs(i + dx[d], j + dy[d]);
    }
    return ret;
}
int main() {
    su(n);
    su(m);
    char c;
    for (int i = 1; i <= 2 * n + 1; i++) {
        for (int j = 1; j <= 2 * m + 1; j++) {
            sc(c);
            vis[i][j] = c != '.';
        }
    }
    vector<int> ans;
    for (int i = 1; i <= 2 * n + 1; i++)
        for (int j = 1; j <= 2 * m + 1; j++)
            if (!vis[i][j])
                ans.push_back(dfs(i, j));

    sort(ans.begin(), ans.end(), greater<int>());
    for (int i : ans) printf("%d ", i);

    return 0;
}