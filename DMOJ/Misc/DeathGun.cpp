// Death Gun

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

unordered_map<string, int> mp;
vi arr[2 * 910];
int in[2 * 910];
int n;
string name[2 * 910];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if (!mp.count(s1)) {
            mp[s1] = cnt;
            name[cnt] = s1;
            cnt++;
        }
        if (!mp.count(s2)) {
            mp[s2] = cnt;
            name[cnt] = s2;
            cnt++;
        }
        arr[mp[s2]].pb(mp[s1]);
        in[mp[s1]]++;
    }
    while (true) {
        int id = -1;
        for (int i = 0; i < cnt; i++)
            if (in[i] == 0) {
                in[i]--;
                id = i;
                break;
            }
        if (id == -1) break;
        cout << name[id] << endl;
        for (int v = 0; v < arr[id].size(); v++) {
            in[arr[id][v]]--;
        }
    }

    return 0;
}