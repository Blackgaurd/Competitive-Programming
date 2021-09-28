// Duty Of Call

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
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

const int MM = 5e5 + 5;
int n, r, dis[MM];
bool in[MM];
vi adj[MM];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        for (int j = 1; j <= num; j++) {
            int a;
            cin >> a;
            in[a] = true;
            adj[i].pb(a);
            adj[a].pb(i);
        }
    }
    for (int i = 1; i <= n; i++) cout << in[i] << " ";
    cout << nl;
    ms(dis, -1, MM);
    int count[2] = {0, 0};
    qi q;
    q.pb(r);
    dis[r] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        if (!in[cur]) count[dis[cur] % 2]++;
        for (auto nxt : adj[cur]) {
            if (dis[nxt] < 0) {
                q.pb(nxt);
                dis[nxt] = dis[cur] + 1;
            }
        }
    }
    cout << count[0] << " " << count[1];

    return 0;
}