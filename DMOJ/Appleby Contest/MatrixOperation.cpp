// Appleby Contest '19 P5 - Matrix Operation

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

const int MM = 1503;
int n, arr[MM][MM], dp[MM][MM], ans = 0, dx[] = {-1, 1, 0, 0},
                                dy[] = {0, 0, -1, 1};
int dfs(int x, int y) {
    if (dp[x][y] != 0) return dp[x][y];
    bool flag = false;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (arr[nx][ny] > arr[x][y]) {
            dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
            flag = true;
        }
    }
    if (flag)
        return dp[x][y];
    else
        return dp[x][y] = 1;
}
int main() {
    su(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            su(arr[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans = max(ans, dfs(i, j));
        }
    }
    printf("%d\n", ans - 1);

    return 0;
}