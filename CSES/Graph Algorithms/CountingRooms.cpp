// Counting Rooms

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

const int MM = 1e3 + 3;
int n, m, dis[MM][MM], ans, dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
void dfs(int i, int j) {
    dis[i][j] = -1;
    for (int d = 0; d < 4; d++) {
        if (dis[i + dx[d]][j + dy[d]] != -1) {
            dfs(i + dx[d], j + dy[d]);
        }
    }
}
int main() {
    su(n);
    su(m);
    memset(dis, -1, sizeof(dis));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            sc(c);
            dis[i][j] = c == '#' ? -1 : 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dis[i][j] == -1) continue;
            dfs(i, j);
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}