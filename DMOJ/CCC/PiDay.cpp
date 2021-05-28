// CCC '15 J5 - π-day

#include<bits/stdc++.h>
using namespace std;

const int MM = 256;
int n, k, dp[MM][MM];
int solve(int a, int b){
    if (a<0 || a!=0 && b==0) return 0;
    if (a==0 && b!=0) return 1;
    if (dp[a][b]!=0) return dp[a][b];
    dp[a][b] = solve(a-b, b) + solve(a, b-1);
    return dp[a][b];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    cout << solve(n-k, k) << '\n';
    return 0;
}