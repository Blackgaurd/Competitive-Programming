// CCC '03 S4 - Substrings

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 5003, base = 131, MOD = 1e9+7;
int n;
ll h[MM], p[MM]; // (h)ash, (p)ower
string s;
ll sub_hash(int l, int r){
    return (h[r] - h[l-1] * p[r-l+1] % MOD + MOD) % MOD;
}
int solve(){
    int m = s.size();
    unordered_set<ll> cnt;
    for (int i=1; i<=m; i++){
        h[i] = (h[i-1] * base + s[i-1]) % MOD;
    }
    for (int start=1; start<=m; start++){
        for (int len=0; start+len<=m; len++){
            cnt.insert(sub_hash(start, start+len));
        }
    }
    return cnt.size() + 1; // add one for empty substring
}
int main(){
    cin >> n;
    p[0] = 1;
    for (int i=1; i<MM; i++){
        p[i] = p[i-1] * base % MOD;
    }
    while (n--){
        cin >> s;
        cout << solve() << '\n';
    }

    return 0;
}