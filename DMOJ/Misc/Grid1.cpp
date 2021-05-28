
#include<iostream>
using namespace std;

const int mod = 1e9+7;
int r, c, dp[1003][1003];
int check(int x){
    if (x==-1) return 0;
    return x;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> r >> c;
    dp[0][1] = 1;
    for (int i=1; i<=r; i++){
        for (int j=1; j<=c; j++){
            char a; cin >> a;
            if (a=='#') dp[i][j] = -1;
            else {
                dp[i][j] = check(dp[i-1][j]) + check(dp[i][j-1]);
                dp[i][j]%=mod;
            }
        }
    }
    cout << dp[r][c];

    return 0;
}