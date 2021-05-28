// Travelling Salesmen

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MM = 1e5+3;
int n, m, k, ans = 0, dis[MM];
vector<int> adj[MM];
int main(){
    sc(n); sc(m);
    for (int i=0; i<m; i++){
        int a, b; sc(a); sc(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    deque<int> q;
    sc(k);
    fill(dis, dis+MM, -1);
    for (int i=0; i<k; i++){
        int a; sc(a);
        q.push_back(a);
        dis[a] = 0;
    }
    while (!q.empty()){
        int cur = q.front(); q.pop_front();
        ans = max(ans, dis[cur]);
        for (int nxt: adj[cur]){
            if (dis[nxt]==-1){
                q.push_back(nxt);
                dis[nxt] = dis[cur]+1;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}