// BSSPC '21 J6 - Lakshy and Orz Trees

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pll;
#define watch(x) cout << (#x) << ": " << x << '\n'

const int MM = 5e5+3;
ll n, cost[MM], ans = 0;
vector<int> adj[MM];
int dfs1(int cur, int pre){
    int ret = cost[cur];
    for (int nxt: adj[cur]){
        if (nxt != pre)
            ret += dfs1(nxt, cur);
    }
    return ret;
}
ll dfs2(int cur, int pre){

}
int main(){
    cin >> n;
    for (int i=2; i<=n; i++) cin >> cost[i];
    for (int i=1; i<n; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

}

/*
14
2 3 4 5 6 7 8 9 10 11 12 13 14
1 2
2 6
2 7
2 8
3 1
9 3
10 3
4 11
12 4
5 13
5 14
1 5
1 4
*/