// DMOPC '13 Contest 3 P3 - Crossing Field

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
typedef pair<int, int> pii;

const int MM = 1501;
int n, h, arr[MM][MM], dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
bool vis[MM][MM];
queue<pii> q;
int main() {
    su(n);
    su(h);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            su(arr[i][j]);
        }
    }
    q.push({1, 1});
    vis[1][1] = true;
    while (!q.empty()) {
        int curx = q.front().first, cury = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i], ny = cury + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (!vis[nx][ny] && abs(arr[curx][cury] - arr[nx][ny]) <= h) {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    printf("%s\n", vis[n][n] ? "yes" : "no");

    return 0;
}