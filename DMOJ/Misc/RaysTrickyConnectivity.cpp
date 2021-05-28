// Ray's Tricky Connectivity

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;
int n, m, q;
vector<int> adj[400003];
bool reach[400003];
void dfs(int cur){
    reach[cur] = true;
    for (int nxt: adj[cur])
        if (!reach[nxt]) dfs(nxt);
}
int main(){ 
    sc(n); sc(m); sc(q);
    for (int i=0; i<m; i++){
        int a, b; sc(a); sc(b);
        adj[a].push_back(b);
    }
    dfs(1);
    for (int i=0; i<q; i++){
        char c; cin >> c;
        if (c=='+'){
            int a, b; sc(a); sc(b);
            adj[a].push_back(b);
            if (reach[a] && !reach[b]) dfs(b);
        }
        else if (c=='?'){
            int a; sc(a);
            cout << (reach[a]?"YES\n":"NO\n");
        }
    }


    return 0;
}