// Cat Lovers

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;
using qi = queue<int>;
using qpii = queue<pii>;
#define ms memset;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    int c = 0;
    for (int i=0; i<n; i++){
        string s;
        cin >> s;
        if (s=="cats") c++;
        else c--;
    }
    if (c>0) cout << "cats";
    else if (c<0) cout << "dogs";
    else cout << "equal";

    return 0;
}