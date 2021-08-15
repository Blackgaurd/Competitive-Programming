// CCC '20 S3 - Searching for Strings

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 2e5+3, base1 = 131, base2 = 137, MOD = 1e9+7;
string a, b;
vector<int> fa(26), fb(26); // freq arrays for a and b
ll h1[MM], h2[MM], p1[MM], p2[MM]; // (h)ash and (p)ower arrays
struct pair_hash{
    template <class T1, class T2>
    size_t operator () (pair<T1, T2> const &pair) const{
        size_t h1 = hash<T1>()(pair.first);
        size_t h2 = hash<T2>()(pair.second);
        return h1 ^ h2;
    }
};
unordered_set<pair<ll, ll>, pair_hash> seen;
ll sub_hash1(int l, int r){
    return (h1[r] - h1[l-1] * p1[r-l+1] % MOD + MOD) % MOD;
}
ll sub_hash2(int l, int r){
    return (h2[r] - h2[l-1] * p2[r-l+1] % MOD + MOD) % MOD;
}
int main(){
    cin >> a >> b;
    int n = a.size(), m = b.size();
    for (char c: a) fa[c-'a']++;
    p1[0] = p2[0] = 1;
    for (int i=1; i<=m; i++){
        h1[i] = (h1[i-1] * base1 + b[i-1]) % MOD;
        p1[i] = p1[i-1] * base1 % MOD;

        h2[i] = (h2[i-1] * base2 + b[i-1]) % MOD;
        p2[i] = p2[i-1] * base2 % MOD;
    }
    for (int i=1; i<=m; i++){
        fb[b[i-1]-'a']++;
        if (i > n) fb[b[i-1-n]-'a']--;
        if (i >= n && fa == fb)
            seen.insert({sub_hash1(i-n+1, i), sub_hash2(i-n+1, i)});
    }
    printf("%ld\n", seen.size());

    return 0;
}