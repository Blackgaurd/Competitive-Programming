// MNYC '17: Hurontario

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e6+3, base = 13, MOD = 1e9+7;
string a, b;
int n, m;
ll ha[MM], hb[MM], pw[MM];
ll pre_hash(int len){
    return hb[len];
}
ll post_hash(int len){
    int l = n - len + 1, r = n;
    return (ha[r] - ha[l-1] * pw[r-l+1] % MOD + MOD) % MOD;
}
int main(){
    cin >> a >> b;
    n = a.size(), m = b.size();
    pw[0] = 1;
    for (int i=1; i<=max(n, m); i++){
        if (i <= n)
            ha[i] = (ha[i-1] * base + a[i-1]) % MOD;
        if (i <= m)
            hb[i] = (hb[i-1] * base + b[i-1]) % MOD;
        pw[i] = pw[i-1] * base % MOD;
    }
    for (int len=min(n, m); len>=1; len--){
        if (post_hash(len) == pre_hash(len)){
            cout << a.substr(0, n-len) << b << '\n';
            return 0;
        }
    }
    cout << a << b << '\n';

    return 0;
}
