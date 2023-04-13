// Labyrinth

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

const int MM = 1e3 + 3;
int n, m;
char par[MM][MM], dpar[] = {'L', 'R', 'U', 'D'};
bool vis[MM][MM];
pii A, B, d4[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main() {
    su(n);
    su(m);
    char c;
    memset(vis, true, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            vis[i][j] = false;
            sc(c);
            if (c == '#') {
                vis[i][j] = true;
            } else if (c == 'A') {
                A = {i, j};
            } else if (c == 'B') {
                B = {i, j};
            }
        }
    }

    // B -> A
    deque<pii> q = {B};
    vis[B.first][B.second] = true;
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop_front();
        for (int i = 0; i < 4; i++) {
            auto [dx, dy] = d4[i];
            int nx = cx + dx, ny = cy + dy;

            if (vis[nx][ny]) continue;
            vis[nx][ny] = true;
            par[nx][ny] = dpar[i];
            q.emplace_back(nx, ny);
        }
    }

    if (!vis[A.first][A.second]) {
        printf("NO\n");
        return 0;
    }

    // trace back
    string ans = "";
    for (pii cur = A; cur != B;) {
        char dir = par[cur.first][cur.second];
        ans.push_back(dir);
        if (dir == 'U') {
            cur.first--;
        } else if (dir == 'D') {
            cur.first++;
        } else if (dir == 'R') {
            cur.second++;
        } else if (dir == 'L') {
            cur.second--;
        }
    }
    printf("YES\n%ld\n%s\n", ans.size(), ans.c_str());
}