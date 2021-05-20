// DMOPC '14 Contest 2 P5 - Sawmill Scheme

#include<bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

const int MM = 1e6+3;
int n, m, out[MM];
bool vis[MM];
vector<int> adj[MM];
double prob[MM]; // assuming there are no loops bc all flowing south
double dfs(int cur){
    if (vis[cur]){
        return prob[cur] / out[cur];
    }
    for (int nxt: adj[cur]){
        prob[cur] += dfs(nxt);
    }
    vis[cur] = true;
    if (out[cur]) return prob[cur] / out[cur];
    else return prob[cur];
}
int main(){
    su(n); su(m);
    for (int i=0, a, b; i<m; i++){
        su(a); su(b);
        adj[b].emplace_back(a);
        out[a]++;
    }
    prob[1] = 1.0;
    vis[1] = true;
    for (int i=2; i<=n; i++)
        if (!out[i])
            printf("%.10f\n", dfs(i));

    return 0;
}