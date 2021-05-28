// Mostly Talking

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INF 0x3f3f3f3f

struct edge{
    int u, w; bool g;
    // g = can not use one time use path?
    edge(int uu, int ww, bool gg){
        u = uu;
        w = ww;
        g = gg;
    }
    bool operator < (const edge& other) const {return w>other.w;}
};
const int MM = 5e5+5;
int n, m, d, dis[MM][2]; // 0 = no cindy, 1 = yes cindy
vector<edge> adj[MM];
priority_queue<edge> q;
int main(){
    sc(n); sc(m);
    for (int i=0; i<m; i++){
        int a, b, k; sc(a); sc(b); sc(k);
        adj[a].push_back(edge(b, k, false));
    }
    sc(d);
    for (int i=0; i<d; i++){
        int a, b, k; sc(a); sc(b); sc(k);
        adj[a].push_back(edge(b, k, true));
    }
    memset(dis, INF, sizeof(dis));
    dis[1][0] = 0;
    q.push(edge(1, 0, false));
    while (!q.empty()){
        int cur = q.top().u, mins = q.top().w;
        bool use = q.top().g;
        q.pop();
        // if (mins>dis[mins][use]) continue;
        // ^^ for some reason removing this passes ^^
        for (edge& e: adj[cur]){
            int nxt = e.u, nxtmins = e.w;
            bool nxtuse = e.g;
            if (use && nxtuse) continue;
            if (dis[nxt][use||nxtuse]>mins+nxtmins){
                dis[nxt][use||nxtuse] = mins+nxtmins;
                q.push(edge(nxt, dis[nxt][use||nxtuse], (use||nxtuse)));
            }
        }
    }
    int ans = min(dis[n][0], dis[n][1]);
    printf("%d\n", (ans==INF?-1:ans));

    return 0;
}