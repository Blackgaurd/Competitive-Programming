// WC '16 Contest 3 S2 - Training Regimen
// MST + find most valuable farm

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;
using pii = pair<int, int>;

const int MM = 2e5+3;
int n, m, gym[MM], lvl = 0, mins = 0, mingym, p[MM];
vector<pii> adj[MM];
priority_queue<pii, vector<pii>, greater<pii>> q;
int flead(int x){
    if (p[x]!=x) p[x] = flead(p[x]);
    return p[x];
}
int main(){
    sc(n); sc(m);
    for (int i=1; i<=m; i++)
        sc(gym[i]);
    mingym = gym[1];
    for (int i=1; i<=n; i++){
        int a, b, w; sc(a); sc(b); sc(w);
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }
    for (int i=1; i<=m; i++) p[i] = i;
    


    return 0;
}