// CCC '13 S4 - Who is Taller?

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

const int MM = 1e6+3;
int n, m, p, qq;
vector<int> adj[MM];
bool vis[MM];
void dfs(int cur){
    vis[cur] = true;
    for (int nxt: adj[cur]){
        if (!vis[nxt]) dfs(nxt);
    }
}
int main(){
    sc(n); sc(m);
    for (int i=0; i<m; i++){
        int a, b; sc(a); sc(b);
        adj[a].push_back(b);
    }
    sc(p); sc(qq);
    dfs(p);
    if (vis[qq]) cout << "yes\n";
    else {
        memset(vis, false, sizeof(vis));
        dfs(qq);
        if (vis[p]) cout << "no\n";
        else cout << "unknown\n";
    }

    return 0;
}