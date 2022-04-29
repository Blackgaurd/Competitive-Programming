// Distinct Shapes

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
typedef long long ll;

const int MM = 2003, base1 = 131, base2 = 101, MOD = 1e9 + 7;
int n, m, minx, miny;
char arr[MM][MM];
vector<pii> island;
pii dir[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
set<pii> cnt;
void dfs(int cx, int cy) {
    arr[cx][cy] = '.';
    island.emplace_back(cx, cy);
    minx = min(minx, cx);
    miny = min(miny, cy);
    for (auto [dx, dy] : dir) {
        int nx = cx + dx, ny = cy + dy;
        if (nx <= 0 || nx > n) continue;
        if (ny <= 0 || ny > m) continue;
        if (arr[nx][ny] == '#') {
            dfs(nx, ny);
        }
    }
}
int hash_i(int base) {
    ll h = 0;
    for (auto [x, y] : island) {
        h = (h * base + x) % MOD;
        h = (h * base + y) % MOD;
    }
    return h;
}
int main() {
    su(n);
    su(m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sc(arr[i][j]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == '#') {
                island.clear();
                minx = miny = INT_MAX;
                dfs(i, j);
                sort(island.begin(), island.end());
                for (auto &[x, y] : island) {
                    x -= minx - 1;
                    y -= miny - 1;
                }
                cnt.insert({hash_i(base1), hash_i(base2)});
            }
        }
    }
    printf("%ld\n", cnt.size());
}
