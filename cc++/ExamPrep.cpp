// Exam Prep

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = queue<int>;

const int MM = 1e6+5;
int n, q, notes[MM];
pair<int, long long> adj[MM];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i=1; i<=n; i++) cin >> notes[i];
    while (q--){
        int c; cin >> c;
        if (c==1){
            int a, b; cin >> a >> b;
            adj[a].first++;
            adj[a].second+=notes[b];
            adj[b].first++;
            adj[b].second+=notes[a];
        }
        else if (c==2){
            int a; cin >> a;
            cout << adj[a].first;
        }
        else{
            int a; cin >> a;
            cout << adj[a].second;
        }
    }

    return 0;
}