// CCC '01 S3 - Strategic Bombing

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = queue<int>;
#define pb push_back
#define nl '\n'

vi adj[27];
queue<pii> q;
bool vis[27];
set<int> nodes;
int disconnecting = 0;
bool bfs(int x, int y) {
    qi q;
    q.push(x);
    vis[x] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto nxt : adj[cur]) {
            if (cur == x && nxt == y)
                continue;
            else if (cur == y && nxt == x)
                continue;
            if (!vis[nxt]) {
                vis[nxt] = true;
                q.push(nxt);
            }
        }
    }
    for (auto i : nodes) {
        if (!vis[i]) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    while (true) {
        string t;
        cin >> t;
        if (t == "**") break;
        int a = t[0] - '@', b = t[1] - '@';
        adj[a].pb(b);
        adj[b].pb(a);
        q.push(make_pair(a, b));
        nodes.insert(a);
        nodes.insert(b);
    }
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        if (bfs(cur.first, cur.second)) {
            disconnecting++;
            char a = (char)(cur.first + '@'), b = (char)(cur.second + '@');
            cout << a << b << nl;
        }
        memset(vis, false, 27);
    }
    cout << "There are " << disconnecting << " disconnecting roads." << nl;

    return 0;
}