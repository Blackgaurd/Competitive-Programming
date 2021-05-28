// Bob's Video Game

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;
#define INF 0x3f3f3f3f

int n, m, t, adj[303][303];
int main(){
    sc(n); sc(m); sc(t);
    memset(adj, INF, sizeof(adj));
    for (int i=1; i<=m; i++){
        int u, v, w; sc(u); sc(v); sc(w);
        adj[u][v] = w;
    }
    for (int mid=1; mid<=n; mid++){
        for (int start=1; start<=n; start++){
            for (int to=1; to<=n; to++){
                adj[start][to] = min(adj[start][to], max(adj[start][mid], adj[mid][to]));
            }
        }
    }
    for (int i=0; i<t; i++){
        int u, v; sc(u); sc(v);
        printf("%d\n", (adj[u][v]==INF? -1:adj[u][v]));
    }

    return 0;
}