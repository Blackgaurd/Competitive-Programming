#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int MM = 2e5 + 3;
int k, n, m;
vector<pii> grass;
vector<int> nohj;
map<double, int> ranges;
unordered_map<int, double> coord;
ll psa[MM];
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n >> m;
    grass.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> grass[i].first >> grass[i].second;
    }
    nohj.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> nohj[i];
    }
    sort(grass.begin(), grass.end());
    sort(nohj.begin(), nohj.end());
    int pn = 0;
    for (int i = 0; i < grass.size(); i++) {
        while (pn < nohj.size() && abs(nohj[pn] - grass[i].first) > abs(nohj[pn + 1] - grass[i].first)) pn++;
        double diff = -0.5 + abs(nohj[pn] - grass[i].first);
        ranges[double(grass[i].first) + diff + 1] -= grass[i].second;
        ranges[double(grass[i].first) - diff] += grass[i].second;
    }
    int ptr = 1;
    for (auto [a, b]: ranges){
        coord[ptr++] = a;
    }
    for (auto [a, b]: coord) cout << a << ' ' << b << '\n';
    ptr--;
    for (int i=1; i<=ptr; i++){
        psa[i] = ranges[coord[i]];
        psa[i] += psa[i-1];
        cout << psa[i] << ' ';
    }
}