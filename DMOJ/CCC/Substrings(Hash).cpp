// CCC '03 S4 - Substrings
// hashing

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int p = 67, MOD = 1e9+7;
int n;
vector<ll> p_pow;
int get(char c){
    if ('a' <= c  && c <= 'z')
        return c - 'a' + 1;
    if ('A' <= c && c <= 'Z')
        return c - 'A' + 27;
    if ('0' <= c && c <= '9')
        return c - '0' + 53;
    return -1;
}
int solve(string const& s){
    int len = s.length(), ret = 0;
    vector<ll> hashes = {0};
    for (int i=0; i<len; i++)
        hashes.push_back((hashes.back() + get(s[i]) * p_pow[i]) % MOD);

    set<ll> cnt;
    for (int l=1; l<=len; l++){
        for (int i=0; i<=len-l; i++){
            ll cur_h = (hashes[i+l] + MOD - hashes[i]) % MOD;
            cur_h = (cur_h * p_pow[len-i-1]) % MOD;
            cnt.insert(cur_h);
        }
        ret += cnt.size();
        cnt.clear();
    }
    return ret + 1; // empty substr
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    p_pow.push_back(1);
    for (int i=1; i<=5000; i++)
        p_pow.push_back((p_pow.back() * p) % MOD);

    cin >> n;
    while (n--){
        string a; cin >> a;
        cout << solve(a) << '\n';
    }

    return 0;
}