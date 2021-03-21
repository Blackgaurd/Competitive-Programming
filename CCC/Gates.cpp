// CCC '15 S3 - Gates

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
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

const int MM = 1e5+5;
int g, p, cnt = 0, arr[MM];
set<int> s;
bool dock[MM];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> g >> p;
    for (int i=1; i<=g; i++) s.insert(i);
    for (auto j: s) cout << j << " ";
    cout << nl << nl;
    for (int i=1; i<=p; i++) cin >> arr[i];
    for (int i=1; i<=p; i++){
        int a = arr[i];
        set<int>::iterator it = max_element(begin(s), lower_bound(begin(s), end(s), a));
        s.erase(*it);
        cout << *it << nl;
        for (auto j: s) cout << j << " ";
        cout << nl;
    }

    return 0;
}