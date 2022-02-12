// MNYC '16: Jelly

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

const int MM = 152;
int x, y, z, arr[MM][MM][MM], dis[MM][MM][MM], ans = INT_MAX;
struct pos {
    int z, x, y;
};
queue<pos> q;
pos dir[] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};
int main() {
    su(x);
    su(y);
    su(z);
    char c;
    for (int i = 1; i <= z; i++) {
        for (int j = 1; j <= x; j++) {
            for (int k = 1; k <= y; k++) {
                sc(c);
                if (c == 'J') {
                    q.push({i, j, k});
                } else {
                    arr[i][j][k] = c - '0';
                    dis[i][j][k] = INT_MAX;
                }
            }
        }
    }
    while (!q.empty()) {
        auto [cz, cx, cy] = q.front();
        q.pop();
        if (cz == 1 || cz == z || cy == 1 || cy == y || cx == 1 || cx == x) {
            ans = min(ans, dis[cz][cx][cy]);
            continue;
        }
        for (auto [dz, dx, dy] : dir) {
            int nz = cz + dz, nx = cx + dx, ny = cy + dy;
            if (nz < 1 || nz > z || ny < 1 || ny > y || nx < 1 || nx > x) continue;
            if (dis[cz][cx][cy] + arr[nz][nx][ny] < dis[nz][nx][ny]){
                dis[nz][nx][ny] = dis[cz][cx][cy] + arr[nz][nx][ny];
                q.push({nz, nx, ny});
            }
        }
    }
    printf("%d\n", ans);
}