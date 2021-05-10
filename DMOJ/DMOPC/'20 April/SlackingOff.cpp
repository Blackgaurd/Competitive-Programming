// DMOPC '20 Contest 5 P4 - Slacking Off
// partials

#include<bits/stdc++.h>
using namespace std;

const int MM = 503;
int n, m, ans = 0;
bool arr[MM][MM];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            char c; cin >> c;
            arr[i][j] = (c == 'Y');
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            for (int len=1; len+i<n; len++){
                bool flag = true;
                for (int ind=i; ind<=i+len; i++){
                    if (arr)
                }
            }
        }
    }
    
    return 0;
}