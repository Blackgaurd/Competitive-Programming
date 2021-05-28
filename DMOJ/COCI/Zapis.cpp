// COCI '07 Contest 1 #4 Zapis

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 203, MOD = 1e5;
ll n, dp[MM][MM];
string t;
bool close(char c){
    return c == ']' || c == '}' || c == ')';
}
bool open(char c){
    return c == '[' || c == '{' || c == '(';
}
int check(char a, char b){
    if (a == '?' && b == '?') return 3;
    if (a == '?' || b == '?') return 1;
    if ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']')) return 1;
    return 0;
}
ll solve(int l, int r){
    if (l >= r) return 1;
    if (dp[l][r] != -1) return dp[l][r];
    dp[l][r] = 0;
    for (int m=l+1; m<=r; m+=2){
        if(close(t[l]) || open(t[m])) continue;
        dp[l][r] += solve(l+1, m-1) * solve(m+1, r) * check(t[l], t[m]);
        if (dp[l][r] >= MOD) dp[l][r] = dp[l][r] % MOD + MOD;
    }
    return dp[l][r];
}
int main(){
    cin >> n >> t;
    memset(dp, -1, sizeof(dp));
    ll ans = solve(0, n-1);
    if (ans >= MOD){
        cout << setfill('0') << setw(5) << ans % MOD << '\n';
    }
    else cout << ans << '\n';

    return 0;
}