// Bulgarian OI '09 P2 - Boxen

#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

unordered_map<int, vector<int> > adj;
bool vis[100005];
int solve(){
    // take inputs and make graph
    // box with key points to box it can open
    int n; scan(n);
    for (int i=1; i<=n; i++){
        int a; scan(a);
        adj[a].push_back(i);
    }
    // run bfs
    int ans = 0;
    // try and start bfs from every num 1..n
    set<int> current_path;
    for (int i=1; i<=n; i++){
        // if not previously visited
        if (!vis[i]){
            ans++;
            // search starting from i
            deque<int> q = {i};
            current_path.clear();
            while (!q.empty()){
                int cur = q.front();
                q.pop_front();
                current_path.insert(cur);
                vis[cur] = true;
                for (auto nxt: adj[cur]){
                    if (!vis[nxt]){
                        q.push_back(nxt);
                    }
                    // make sure not subtracting if theres loop
                    else if (!current_path.count(nxt)) ans--;
                }
            }
        }
    }
    memset(vis, false, sizeof(vis));
    adj.clear();
    return ans;
}
int main(){
    int a = solve(), b = solve();
    cout << a << ' ' << b;
}