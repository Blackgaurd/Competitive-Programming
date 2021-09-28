// You Might be a Redneck

#include <bits/stdc++.h>
using namespace std;

int t, n, jim;
unordered_map<int, vector<int>> adj, rev;
set<int> vis;
hash<string> hasher;
bool redneck = false;
void dfs1(int cur) {
    vis.insert(cur);
    for (int nxt : adj[cur]) {
        if (vis.count(nxt)) {
            redneck = true;
            return;
        } else
            dfs1(nxt);
    }
}
void dfs2(int cur) {
    vis.insert(cur);
    for (int nxt : rev[cur]) {
        if (vis.count(nxt)) {
            redneck = true;
            return;
        } else
            dfs2(nxt);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    jim = hasher("Jim-Bob");
    cin >> t;
    while (t--) {
        cin >> n;
        while (n--) {
            string child;
            int p;
            cin >> child >> p;
            int c_hash = hasher(child);
            for (int i = 0; i < p; i++) {
                string par;
                cin >> par;
                int p_hash = hasher(par);
                adj[c_hash].push_back(p_hash);
                rev[p_hash].push_back(c_hash);
            }
        }
        dfs1(jim);
        if (redneck) goto FOUND;
        vis.clear();
        dfs2(jim);
    FOUND:
        cout << (redneck ? "Redneck\n" : "Not a redneck\n");
        redneck = false;
        adj.clear();
        rev.clear();
        vis.clear();
    }

    return 0;
}
