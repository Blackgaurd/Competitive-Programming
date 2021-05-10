// CCC '07 S3 - Friends

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

int n;
vector<int> adj[10000];
bool vis[10000];
int dfs(int cur, int dep){
    vis[cur] = true;
    for (int nxt: adj[cur]){
        if (!vis[nxt]) dfs(nxt, dep+1);
    }
}
int main(){
    sc(n);
    while (n--){
        int a, b; sc(a); sc(b);
        adj[a].push_back(b);
    }
    while (true){
        int a, b; sc(a); sc(b);
        if (!a && !b) break;
        
    }

    return 0;
}