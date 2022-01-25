// CCC '18 S3 - RoboThieves

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

int n, m, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
vector<vector<char>> arr;
vector<vector<int>> dis;
deque<pii> q;
template <typename... T>
bool is_in(char first, T &&...t) {
    return ((first == t) || ...);
}
int main() {
#ifdef PC
    freopen("RoboThieves.in", "r", stdin);
    freopen("RoboThieves.out", "w", stdout);
#endif
    // input
    su(n);
    su(m);
    arr.assign(n, vector<char>(m));
    dis.assign(n, vector<int>(m, INT_MAX));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sc(arr[i][j]);
            if (arr[i][j] == 'S') {
                q.emplace_back(i, j);
                dis[i][j] = 0;
            }
        }
    }

    // cameras
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (arr[i][j] == 'C') {
                for (int d = 0; d < 4; d++) {
                    int x = i, y = j;
                    while (arr[x][y] != 'W') {
                        x += dx[d];
                        y += dy[d];
                        if (!is_in(arr[x][y], 'U', 'D', 'L', 'R')) dis[x][y] = -1;
                    }
                }
            }
        }
    }

    // edge case, S starts seen by camera
    if (dis[q.front().first][q.front().second] == -1) {
        dis.assign(n, vector<int>(m, -1));
        goto print;
    }

    // graph fill
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop_front();
        bool conv = is_in(arr[x][y], 'U', 'D', 'L', 'R');
        int start, end;
        switch (arr[x][y]) {
            case 'U':
                start = end = 0;
                break;
            case 'D':
                start = end = 1;
                break;
            case 'L':
                start = end = 2;
                break;
            case 'R':
                start = end = 3;
                break;
            default:
                start = 0;
                end = 3;
                break;
        }
        int add = !conv;
        for (int d = start; d <= end; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (arr[nx][ny] == 'W') continue;
            if (dis[x][y] + add < dis[nx][ny]) {
                dis[nx][ny] = dis[x][y] + add;
                q.emplace_back(nx, ny);
            }
        }
    }
print:
    for (int i = 1; i < n - 1; i++)
        for (int j = 1; j < m - 1; j++)
            if (arr[i][j] == '.')
                printf("%d\n", dis[i][j] == INT_MAX ? -1 : dis[i][j]);

    return 0;
}