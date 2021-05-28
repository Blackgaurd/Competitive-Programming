// Returning Home

#include<bits/stdc++.h>
using namespace std;

const int MM = 33;
int n, m, s, ans = 0;
string t;
vector<string> streets;
set<pair<int, int>> pairs;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> s;
    for (int i=0; i<n; i++){
        cin >> t;
        streets.push_back(t);
    }

    for (int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        pairs.emplace(a - 1, b - 1);
    }

    for (string street: streets){
        bool pal = true;
        for (pair<int, int> ind: pairs){
            for (int l=ind.first, r=ind.second; l<=r; l++, r--){
                if (street[l] != street[r]){
                    pal = false;
                    break;
                }
            }
        }
        if (pal) ans++;
    }
    cout << ans << '\n';


    return 0;
}

