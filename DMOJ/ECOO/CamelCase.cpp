// ECOO '16 R3 P3 - CamelCase

#include<bits/stdc++.h>
using namespace std;

int n, dp[2003][2003];
set<string> dict;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++){
        string t; cin >> t;
        dict.insert(t);
    }
    for (int e=0; e<10; e++){
        string t; cin >> t;
        memset(dp, 0x3f3f3f3f, sizeof(dp));

        for (int i=1; i<=t.length(); i++){
            for (int l=1; l<=i; l++){
                if (dict.find(t.substr(i-l, l)) != dict.end())
                    dp[i-l][i-1] = 1;

                if (i-l > 0)
                    dp[0][i-1] = min(dp[0][i-1], dp[0][i-l-1] + dp[i-l][i-1]);
            }
        }
        cout << dp[0][t.length()-1] - 1 << '\n';
    }

    return 0;
}