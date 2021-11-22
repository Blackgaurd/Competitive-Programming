// B. Two Buttons

#include <bits/stdc++.h>
using namespace std;

const int MM = 1e4 + 3;
int n, m, dis[MM];
deque<int> q;
int main() {
    cin >> n >> m;
    memset(dis, 0x3f, sizeof(dis));
    q.push_back(n);
    dis[n] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        if (cur > 0 && dis[cur] + 1 < dis[cur - 1]) {
            dis[cur - 1] = dis[cur] + 1;
            q.push_back(cur - 1);
        }
        if (cur * 2 <= MM && dis[cur] + 1 < dis[cur * 2]) {
            dis[cur * 2] = dis[cur] + 1;
            q.push_back(cur * 2);
        }
    }
    cout << dis[m] << '\n';

    return 0;
}
