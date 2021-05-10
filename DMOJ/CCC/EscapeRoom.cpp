// CCC '20 S2 - Escape Room

#include <bits/stdc++.h>
using namespace std;

#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

const int MM = 1e6+5;
bool vis[MM];
vector<int> adj[MM];
int n, m;
int main(){
    sc(n); sc(m);
    deque<int> q;
    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            int a; sc(a);
            adj[i*j].push_back(a);
            if (i==1 && j==1) {q.push_back(a); vis[a] = true;}
        }
    }
    while (!q.empty()){
        int cur = q.front();
        q.pop_front();
        if (cur==m*n) {printf("yes\n"); return 0;}
        for (auto nxt: adj[cur]){
            if (!vis[nxt]){
                vis[nxt] = true;
                q.push_back(nxt);
            }
        }
    }
    printf("no\n");

    return 0;
}