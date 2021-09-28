//

#include <bits/stdc++.h>
using namespace std;

const int MM = 3010;
int n, arr[MM][MM], sur[MM][MM], cnt = 0;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
void update(int x, int y) {
    sur[x][y + 1]++;
    sur[x][y - 1]++;
    sur[x + 1][y]++;
    sur[x - 1][y]++;
    arr[x][y] = 1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        x += 1000;
        y += 1000;
        // 0 = empty
        // 1 = filled by added cow
        // 2 = filled by original cow
        if (arr[x][y] == 0) {
            arr[x][y] = 2;
            update(x, y);
        } else if (arr[x][y] == 1) {
            cnt--;
            arr[x][y] = 2;
        }
        deque<pair<int, int>> q;
        q.push_back({x, y});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop_front();
            if (sur[cur.first][cur.second] == 3) {
                for (int i = 0; i < 4; i++) {
                    if (!arr[cur.first + dx[i]][cur.second + dy[i]]) {
                        update(cur.first + dx[i], cur.second + dy[i]);
                        q.push_back({cur.first + dx[i], cur.second + dy[i]});
                        cnt++;
                    }
                }
            }
            for (int i = 0; i < 4; i++) {
                if (sur[cur.first + dx[i]][cur.second + dy[i]] == 3) {
                    q.push_back({cur.first + dx[i], cur.second + dy[i]});
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}