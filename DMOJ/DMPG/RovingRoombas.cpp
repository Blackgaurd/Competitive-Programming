// DMOPC '20 Contest 4 P3 - Roving Roombas

#include<bits/stdc++.h>
using namespace std;

const int MM = 2e5+3;
int n, m, ind = 0, ans = 0;
vector<pair<int, int>> x, y;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        y.push_back({b, a});
    }
    sort(y.begin(), y.end());
    for (int i=0; i<m; i++){
        int pos, ht; cin >> pos >> ht;
        x.push_back({pos, ht});
    }
    sort(x.begin(), x.end());
    for (auto p: x){
        int pos = p.first, ht = p.second;
        for (int i=ind; i<n; i++){
            if (pos > y[i].first) ind++;
            else if (ht >= y[i].second) ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}