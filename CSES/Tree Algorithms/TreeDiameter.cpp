// Tree Diameter

#include <bits/stdc++.h>
using namespace std;
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on

const int MM = 2e5+3;
int n, dis[MM], endpoint, mx = -1;;
vector<int> adj[MM];
void dfs1(int cur, int par){
    dis[cur] = dis[par] + 1;
    for (int nxt: adj[cur]){
        if (nxt != par) dfs1(nxt, cur);
    }
    if (dis[cur] > mx){
        mx = dis[cur];
        endpoint = cur;
    }
}
int main(){
    su(n);
    for (int i=1,a, b; i<n; i++){
        su(a); su(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, 0);
    memset(dis, 0, sizeof(dis));
    dfs1(endpoint, 0);
    printf("%d\n", mx - 1);

    return 0;
}