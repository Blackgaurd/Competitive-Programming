// CCC '18 J5 - Choose your own path

#include<bits/stdc++.h>
using namespace std;

int n, dis[100005], ans = INT_MAX;
vector<int> adj[100005];
bool vis[100005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        int a; cin >> a;
        for (int j=0; j<a; j++){
            int b; cin >> b;
            adj[i].push_back(b);
        }
    }
    
    deque<int> q;
    q.push_back(1);
    dis[1] = 1;
    vis[1] = true;
    while (!q.empty()){
        int cur = q.front();
        q.pop_front();
        // cout << cur << '\n';
        if (adj[cur].size()==0) ans = min(ans, dis[cur]);
        for (auto nxt: adj[cur]){
            if (!vis[nxt]){
                vis[nxt] = true;
                q.push_back(nxt);
                dis[nxt] = dis[cur]+1;
            }
        }
    }
    char all = 'Y';
    for (int i=1; i<=n; i++){
        if (!vis[i]) {all='N'; break;}
    }
    cout << all << '\n' << ans << '\n';
    

    return 0;
}
