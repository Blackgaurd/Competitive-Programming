// Bob's String Power

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e6+3, base = 131, MOD = 1e9+7;
int n, m;
ll hsh[MM], pw[MM];
string t;
bool check(int len){
    ll sub_hsh = hsh[len], ttl_hsh = 0;
    for (int i=0; i<m/len; i++){
        ttl_hsh = (ttl_hsh * pw[len] + sub_hsh) % MOD;
    }
    return ttl_hsh == hsh[m];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    pw[0] = 1;
    while (n--){
        cin >> t;
        m = t.size();
        for (int i=1; i<=m; i++){
            pw[i] = pw[i-1] * base % MOD;
            hsh[i] = (hsh[i-1] * base + t[i-1]) % MOD;
        }
        for (int i=1; i<=m; i++){
            if (m % i == 0 && check(i)){
                cout << m/i << '\n';
                break;
            }
        }
    }

    return 0;
}