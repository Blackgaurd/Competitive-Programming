// B. Not Sitting

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

int t, n, m;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
void solve() {
    su(n);
    su(m);
    int x = (n + 1) / 2, y = (m + 1) / 2;
    int dis = x + y - m % 2 - n % 2;

    vector<vector<int>> arr(n + 1, vector<int>(m + 1, -1));
    deque<pii> q;
    arr[x][y] = dis;
    q.push_back({x, y});
    if (n % 2 == 0) {
        arr[x + 1][y] = dis;
        q.push_back({x + 1, y});
    }
    if (m % 2 == 0) {
        arr[x][y + 1] = dis;
        q.push_back({x, y + 1});
    }
    if (n % 2 == 0 && m % 2 == 0) {
        arr[x + 1][y + 1] = dis;
        q.push_back({x + 1, y + 1});
    }
    while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop_front();
        printf("%d ", arr[a][b]);
        for (int d = 0; d < 4; d++) {
            int nx = a + dx[d], ny = b + dy[d];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (arr[nx][ny] == -1) {
                arr[nx][ny] = arr[a][b] + 1;
                q.push_back({nx, ny});
            }
        }
    }
    printf("\n");
}
int main() {
    su(t);
    while (t--) {
        solve();
    }
}