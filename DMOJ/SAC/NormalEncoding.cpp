// SAC '22 Code Challenge 3 Junior P5 - Normal Encoding

#include <bits/stdc++.h>
using namespace std;

const int MM = 1e4 + 3;
int n, m, dis[MM], par[MM];
string t;
vector<pair<char, string>> arr;
char ans[MM];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;
    arr.resize(n);
    for (auto &[c, s] : arr) cin >> c >> s;
    deque<int> q = {0};
    memset(dis, 0x3f, sizeof(dis));
    dis[0] = 0;
    par[0] = -1;
    while (!q.empty()) {
        int pos = q.front();
        q.pop_front();
        for (auto &[c, s] : arr) {
            if (pos + s.size() <= m && s == t.substr(pos, s.size())) {
                if (dis[pos] + 1 < dis[pos + s.size()]) {
                    dis[pos + s.size()] = dis[pos] + 1;
                    q.push_back(pos + s.size());
                    par[pos + s.size()] = pos;
                    ans[pos] = c;
                } else if (dis[pos] + 1 == dis[pos + s.size()] && ans[pos] > c) {
                    ans[pos] = c;
                }
            }
        }
    }
    for (int i=0; i<m; i++){
        cout << t[i] << ' ' << dis[i] << '\n';
    }
}