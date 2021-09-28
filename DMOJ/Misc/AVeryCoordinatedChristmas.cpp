// A Very Coordinated Christmas
// Run bfs from midpoint

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = queue<int>;
using qpii = queue<pair<int, int>>;

int r, c, MM = 1005, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
pii s, e1, e2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    bool vis[MM][MM];
    int dis[MM][MM] = {{-1}};
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            char c;
            cin >> c;
            if (c == '#')
                vis[i][j] = true;
            else if (c == 'P') {
                s = {i, j};
                dis[i][j] = 0;
                vis[i][j] = true;
            } else if (c == 'X')
                e1 = {i, j};
            else if (c == 'O')
                e2 = {i, j};
        }
    }

    qpii q;
    q.push(s);
    while (!q.empty()) {
        int curx = q.front().first, cury = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (!vis[curx + dx[i]][cury + dy[i]]) {
                vis[curx + dx[i]][cury + dy[i]] = true;
                q.push({curx + dx[i], cury + dy[i]});
                dis[curx + dx[i]][cury + dy[i]] = dis[curx][cury] + 1;
            }
        }
    }

    if (!vis[e1.first][e1.second] || !vis[e2.first][e2.second])
        cout << -1;
    else {
        int sol = dis[e1.first][e1.second] + dis[e2.first][e2.second];
        cout << sol;
    }

    return 0;
}