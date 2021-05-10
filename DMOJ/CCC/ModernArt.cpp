// CCC '21 S2 - Modern Art

#include<bits/stdc++.h>
using namespace std;

const int MM = 5e6+1;
int n, m, k, ans = 0;
bool row[MM], col[MM];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> m >> n >> k;
    while (k--){
        char c; int a;
        cin >> c >> a;
        if (c == 'R') row[a] ^= 1;
        else col[a] ^= 1;
    }
    int black = 0;
    for (int i=1; i<=n; i++)
        if (!col[i]) black++;
    
    for (int i=1; i<=m; i++){
        if (row[i]) ans += black;
        else ans += n - black;
    }
    cout << ans << '\n';
    return 0;
}