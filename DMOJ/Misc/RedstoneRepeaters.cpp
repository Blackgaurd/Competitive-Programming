// Redstone Repeaters

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

int n, e, cycle = 0;
vector<int> adj[1003];
bool vis[1003];
void dfs(int start, int cur){
    vis[cur] = true;
    for (int nxt: adj[cur]){
        if (nxt==start) cycle++;
        else if (!vis[nxt] && nxt>start) dfs(start, nxt);
    }
    vis[cur] = false;
}
int main(){
    sc(n); sc(e);
    for (int i=0; i<e; i++){
        int a, b; sc(a); sc(b);
        adj[a].push_back(b);
    }
    for (int i=1; i<=n; i++) dfs(i, i);
    if (cycle){
        if (cycle==1) cout << "Infinite Loop Present\n";
        else cout << "Infinite Loops Present\n";
    }
    else cout << "No Infinite Loops\n";
    
    return 0;
}