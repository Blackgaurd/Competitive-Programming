// Count Cycles

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#define scan(x)                                 \
    do {                                        \
        while ((x = getchar()) < '0')           \
            ;                                   \
        for (x -= '0'; '0' <= (_ = getchar());  \
             x = (x << 3) + (x << 1) + _ - '0') \
            ;                                   \
    } while (0)
char _;
#define ms memset
#define pb push_back
#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll, ll>;
using qi = deque<int>;
using qpii = deque<pii>;

int n, arr[11][11], cycle = 0;
bool vis[11];

void dfs(int start, int cur) {
    vis[cur] = true;
    for (int nxt = 1; nxt <= n; nxt++) {
        if (!arr[cur][nxt]) continue;
        if (nxt == start)
            cycle++;
        else if (!vis[nxt] && nxt > start)
            dfs(start, nxt);
    }
    vis[cur] = false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    scan(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scan(arr[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        dfs(i, i);
    }
    cout << cycle;

    return 0;
}