#include<bits/stdc++.h>
using namespace std;

string t;
int ans = 0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    string cop = t;
    sort(cop.begin(), cop.end());
    for (int i=0; i<t.size(); i++)
        if (t[i] != cop[i]) ans++;
    ans = min(ans/2, ans-1);
    if (ans == -1) ans = 0;
    cout << ans << '\n';
    
}