// An Animal Contest 2 P3 - Koala Balloons

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
int n, m, psa[MM][MM], dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
bool vis[MM][MM];
bool check(int nx, int ny, int x) {
    if (nx <= 0 || ny <= 0 || nx + x > n || ny + x > m) return false;
    if (vis[nx][ny]) return false;
    return (psa[nx + x][ny + x] - psa[nx - 1][ny + x] - psa[nx + x][ny - 1] +
                psa[nx - 1][ny - 1] ==
            0);
}
bool bfs(int x) {
    x--;
    deque<pii> q;
    memset(vis, false, sizeof(vis));
    if (check(1, 1, x)) {
        q.emplace_back(1, 1);
        vis[1][1] = true;
    }
    while (!q.empty()) {
        int curx = q.front().first, cury = q.front().second;
        q.pop_front();
        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i], ny = cury + dy[i];
            if (check(nx, ny, x)) {
                vis[nx][ny] = true;
                q.emplace_back(nx, ny);
            }
        }
    }
    return vis[n - x][m - x];
}
int main() {
    su(n);
    su(m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            sc(c);
            psa[i][j] = (c == 'X');
            psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
        }
    }
    int lo = 1, hi = min(n, m), ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (bfs(mid)) {
            ans = mid;
            lo = mid + 1;
        } else
            hi = mid - 1;
    }
    printf("%d\n", ans);

    return 0;
}