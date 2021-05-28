// CCC '96 S4 - When in Rome

#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    while (n--){
        string t, a, b; cin >> t;
        int i = 0;
        while (t[i]!='+') a+=t[i];
        i++;
        while (t[i]!='=') b+=t[i];
        cout << a << " " << b << nl;
    }

    return 0;
}