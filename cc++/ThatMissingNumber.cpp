// DWITE '09 R1 #3 - That Missing Number

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
    for (int e=0; e<;5 e++){
        int n; cin >> n;
        bool nums[n+2] = {false};
        for (int i=1; i<=n; i++){
            int a; cin >> a;
            nums[a] = true;
        }
        for (int i=1; i<=n+1; i++){
            if (!nums[i]){
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}