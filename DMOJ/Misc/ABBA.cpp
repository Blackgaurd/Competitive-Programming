// P3 - ABBA

#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

int n;
bool possible = false;
void solve(string a, string b){
    if (a.size()==b.size()){
        if (a==b) {possible = true;}
        return;
    }
    solve(a+"A", b);
    reverse(a.begin(), a.end());
    solve(a+"B", b);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    while (n--){
        string a, b; cin >> a >> b;
        solve(a, b);
        cout << (possible?"YES":"NO") << nl;
        possible = false;
    }
}