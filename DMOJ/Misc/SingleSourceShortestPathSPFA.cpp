// Single Source Shortest Path
// using spfa

#include <bits/stdc++.h>
using namespace std;

int n, m, dis[1003];
bool inque[1003];
vector<pair<int, int>> adj[1003];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }
    fill(dis, dis + 1003, INT_MAX);
    deque<int> q;
    q.push_back(1);
    dis[1] = 0;  // inque[1] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        inque[cur] = false;
        for (auto nxt : adj[cur]) {
            if (dis[cur] + nxt.first < dis[nxt.second]) {
                dis[nxt.second] = dis[cur] + nxt.first;
                if (!inque[nxt.second]) {
                    inque[nxt.second] = true;
                    q.push_back(nxt.second);
                }
            }
        }
        // smallest label first
        if (q.back() < cur) {
            q.push_front(q.back());
            q.pop_back();
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dis[i] != INT_MAX)
            printf("%d\n", dis[i]);
        else
            printf("-1\n");
    }

    return 0;
}