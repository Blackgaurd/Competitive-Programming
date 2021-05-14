// DMPG '15 S6 - Apples to Oranges
// dijkstra but avoid inf loops
// if old value <= 1 and new value > 1 update
// otherwise don't update

#include<bits/stdc++.h>
using namespace std;
typedef pair<double, string> pds;
#define watch(x) cout << (#x) << ": " << x << '\n'

int n, m;
unordered_map<string, vector<pds>> adj;
unordered_map<string, double> dis;
// priority_queue<pds, vector<pds>, greater<pds>> q;
deque<string> q;
set<string> inque;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++){
        string a; cin >> a;
        // adj[a] = {};
        dis[a] = 0.0;
    }
    for (int i=0; i<m; i++){
        string a, b; double w;
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
    }
    

    return 0;
}

/* 3 4
APPLES
ORANGES
GRAPES
APPLES ORANGES 1
ORANGES GRAPES 2
GRAPES ORANGES 1
ORANGES APPLES 0.25 */