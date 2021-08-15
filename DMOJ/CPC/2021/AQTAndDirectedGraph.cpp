// CPC '21 Contest 1 P4 - AQT and Directed Graph

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

const int MM = 3e5+3;
int n, m, a, b, ans[MM];
vector<int> adj[MM];
void dfs(int cur, int start){
    ans[cur] = start;
    for (int nxt: adj[cur]){
        if (!ans[nxt]){
            dfs(nxt, start);
        }
    }
}
int main(){
    su(n); su(m);
    while (m--){
        su(a); su(b);
        adj[b].push_back(a);
    }
    for (int i=n; i>=1; i--){
        if (!ans[i]){
            dfs(i, i);
        }
        else {
            printf("%d %d\n", i, ans[i]);
            return 0;
        }
    }
    printf("-1\n");

    return 0;
}