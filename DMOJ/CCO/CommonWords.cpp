// CCO '99 P2 - Common Words

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = queue<int>;

int n;

bool sorter(pair<string, int>& a, pair<string, int>& b) {return a.second < b.second;}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int e=0; e<n; e++){
        int w, c; cin >> w >> c;
        map<string, int> m;
        vector<pair<string, int>> mv;
        for (int i=0; i<w; i++){
            string t; cin >> t;
            m[t]++;
        }
        for (auto& pair: m) mv.push_back(pair);
        sort(mv.begin(), mv.end(), sorter);
        try{
            cout << mv[c].first << " " << mv[c].second << endl;
        } catch (...) {cout << "-----";}
    }

    return 0;
}