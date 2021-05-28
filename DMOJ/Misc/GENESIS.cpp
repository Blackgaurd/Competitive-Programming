// GENESIS
// idea: lowest weight edge
// in the bath from 1-n
// can be traced back using prev array
// after running spfa / dijkstra
// flaw: multiple paths to get to one node

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;
#define ff first
#define ss second
using pii = pair<int, int>;

const int MM = 103;
int n, m, w[MM], adj[MM][MM], dis[MM], prev_[MM];
bool inque[MM];
int main(){
    memset(adj, 0, sizeof(adj));
    sc(n);
    for (int i=0; i<n-1; i++) sc(w[i]);
    sc(m);
    for (int i=0; i<m; i++){
        int a, b; sc(a); sc(b);
        adj[a][b] = w[i];
    }
    
    deque<int> q = {1};
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    memset(prev_, -1, sizeof(prev_));
    dis[1] = 0;
    prev_[1] = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop_front();
        inque[cur] = false;
        for (int nxt=1; nxt<=n; nxt++){
            if (adj[cur][nxt]){
                if (dis[cur] + adj[cur][nxt] < dis[nxt]){
                    dis[nxt] = dis[cur] + adj[cur][nxt];
                    prev_[nxt] = cur;
                    if (!inque[nxt]){
                        inque[nxt] = true;
                        q.push_back(nxt);
                    }
                }
            }
        }
    }
    int ans = INT_MAX;
    for (int cur = n;; cur = prev_[cur]){
        if (prev_[cur])
            ans = min(ans, adj[prev_[cur]][cur]);
        else break;
    }
    printf("%d\n", ans);

    return 0;
}