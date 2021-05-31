// Rank

#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int> adj[21];
bool vis[21];
set<int> s;
void dfs(int start, int cur, vector<int> pre){
    vis[cur] = true;
    pre.emplace_back(cur);
    for (int nxt: adj[cur]){
        if (nxt == start){
            for (int t: pre) s.insert(t);
        }
        else if (!vis[nxt] && nxt > start)
            dfs(start, nxt, pre);
    }
    vis[cur] = false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i=0, a, b, sa, sb; i<k; i++){
        cin >> a >> b >> sa >> sb;
        if (sa > sb) adj[a].emplace_back(b);
        else adj[b].emplace_back(a);
    }
    for (int i=1; i<=n; i++) dfs(i, i, {});
    printf("%ld\n", s.size());

    return 0;
}