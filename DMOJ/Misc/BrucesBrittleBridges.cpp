// Bruce's Brittle Bridges

#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
vector<pair<int, int>> adj[200003];
int solve(int pre, int cur){
    if (adj[cur].size() == 1) return v[cur];
    int ret = 0;
    for (auto nxt: adj[cur]){
        if (nxt.first != pre){
            if (nxt.second > 1){
                ret += solve(cur, nxt.first);
            }
            else {
                ret = max(ret, solve(cur, nxt.first));
            }
        }
    }
    return ret + v[cur];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    for (int i=0; i<n-1; i++){
        int a, b, t; cin >> a >> b >> t;
        adj[a].push_back({b, t});
        adj[a].push_back({a, t});
    }


    return 0;
}