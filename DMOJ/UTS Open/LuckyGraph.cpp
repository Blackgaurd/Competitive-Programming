// UTS Open '21 P4 - Lucky Graph

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
using pii = pair<int, int>;

int n, m, in[200003], lucky;
vector<pii> adj[200003];
set<int> removed;
int main() {
    sc(n);
    sc(m);
    for (int i = 1; i <= m; i++) {
        int a, b;
        sc(a);
        sc(b);
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        in[a]++;
        in[b]++;
    }
    if (n == 1) {
        cout << 0 << '\n' << 0;
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        if (!(in[i] & 1)) {
            for (int j = 0; j < adj[i].size(); j++) {
                if (!(adj[i][j].first & 1) &&
                    removed.count(adj[i][j].second) == 0) {
                    in[i]--;
                    in[adj[i][j].first]--;
                    removed.insert(adj[i][j].second);
                    // adj[i].erase(adj[i].begin()+j);
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] & 1) {
            lucky++;
        }
    }
    cout << lucky << '\n' << removed.size() << '\n';
    for (int i : removed) cout << i << ' ';

    return 0;
}