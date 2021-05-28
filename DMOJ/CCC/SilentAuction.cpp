#include<bits/stdc++.h>
using namespace std;

int n, most = 0;
unordered_map<int, string> mp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++){
        int a; string t;
        cin >> t >> a;
        most = max(most, a);
        if (!mp[a].size()){
            mp[a] = t;
        }
    }
    cout << mp[most] << '\n';
}