// Balanced Bracket Sequence

#include<bits/stdc++.h>
using namespace std;

string t;
int dp[303][303];
bool match(int a, int b){
    return (t[a] == '(' && t[b] == ')') || (t[a] == '[' && t[b] == ']');
}
int solve(int l, int r){
    if (l >= r) return 1;
    if (dp[l][r] != -1) return dp[l][r];
    if (l+1 == r){
        if (match(l, r)) return 0;
        return 2;
    }
    dp[l][r] = INT_MAX;
    if (match(l, r)) dp[l][r] = min(dp[l][r], solve(l+1, r-1));
    for (int m=l; m<r; m++){
        dp[l][r] = min(dp[l][r], solve(l, m) + solve(m+1, r));
    }
    return dp[l][r];
}
int main(){
    cin >> t;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, t.length()-1) << '\n';
    return 0;
}