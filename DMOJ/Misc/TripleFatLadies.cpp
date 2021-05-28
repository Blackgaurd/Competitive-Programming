// Triple Fat Ladies

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = queue<int>;

int t;
// 192, 442, 692, 942
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> t;
    while (t--){
        int n; cin >> n;
        int md = n%1000;
        n/=1000;
        if (md<=192){
            if (n) cout << n;
            cout << 192;
        }
        else if (md<=442){
            if (n) cout << n;
            cout << 442;
        }
        else if (md<=692){
            if (n) cout << n;
            cout << 692;
        }
        else if (md<=942){
            if (n) cout << n;
            cout << 942;
        } else cout << n+1 << 192;
        cout << endl;
    }

    return 0;
}