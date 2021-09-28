// Tree Tasks

#include <bits/stdc++.h>
using namespace std;
#define sc(x)                                                                  \
    do {                                                                       \
        while ((x = getchar()) < 48)                                           \
            ;                                                                  \
        for (x -= 48; 48 <= (_ = getchar()); x = (x << 3) + (x << 1) + _ - 48) \
            ;                                                                  \
    } while (0)
char _;

const int MM = 5e5 + 5;
int n, dis[MM], dis1[MM];
vector<pair<int, int>> adj[MM];
deque<int> q;
int main() {
    sc(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, w;
        sc(a);
        sc(b);
        sc(w);
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }
    memset(dis, -1, sizeof(dis));
    q.push_back(1);
    dis[1] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        for (auto e : adj[cur]) {
            if (dis[e.second] == -1) {
                dis[e.second] = dis[cur] + e.first;
                q.push_back(e.second);
            }
        }
    }
    int dia = 0, end1;
    for (int i = 1; i <= n; i++) {
        if (dis[i] > dia) {
            dia = dis[i];
            end1 = i;
        }
    }
    memset(dis, -1, sizeof(dis));
    q.push_back(end1);
    dis[end1] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        for (auto e : adj[cur]) {
            if (dis[e.second] == -1) {
                dis[e.second] = dis[cur] + e.first;
                q.push_back(e.second);
            }
        }
    }
    int end2;
    for (int i = 1; i <= n; i++) {
        if (dis[i] > dia) {
            dia = dis[i];
            end2 = i;
        }
    }
    memset(dis1, -1, sizeof(dis1));
    q.push_back(end2);
    dis1[end2] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        for (auto e : adj[cur]) {
            if (dis1[e.second] == -1) {
                dis1[e.second] = dis1[cur] + e.first;
                q.push_back(e.second);
            }
        }
    }
    int rad = INT_MAX;
    for (int i = 1; i <= n; i++) {
        rad = min(rad, max(dis[i], dis1[i]));
    }

    cout << dia << '\n' << rad << '\n';

    return 0;
}