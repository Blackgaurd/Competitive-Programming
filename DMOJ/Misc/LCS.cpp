// LCS

#include<bits/stdc++.h>
using namespace std;

int dp[3003][3003];
char trace[3003][3003];
string a, b;
void print(int i, int j){
    if (!i || !j) return;
    if (trace[i][j] == 'D'){
        print(i-1, j-1);
        cout << a[i-1];
    }
    else if (trace[i][j] == 'U') print(i-1, j);
    else print(i, j-1);
}
int main(){
    cin >> a >> b;
    int n = a.length(), m = b.length();
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                trace[i][j] = 'D';
            }
            else if (dp[i-1][j] >= dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                trace[i][j] = 'U';
            }
            else {
                dp[i][j] = dp[i][j-1];
                trace[i][j] - 'L';
            }
        }
    }
    print(n, m);

    return 0;
}