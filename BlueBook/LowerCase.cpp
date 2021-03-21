// BlueBook - Lower Case

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = queue<int>;
using qpii = queue<pair<int, int>>;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i=0; i<n; i++){
        string t; cin >> t;
        for (auto& ch: t) ch = tolower(ch);
        cout << t << endl;
    }

    return 0;
}