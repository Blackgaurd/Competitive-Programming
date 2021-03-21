// CCC '15 S4 - Convex Hull

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int MM = 2e3+5;
struct edge{
    int dest, mins, hull;
    edge(int e, int t, int h){
        dest = e;
        mins = t;
        hull = h;
    }
    bool operator > (const edge& x) const {return mins>x.mins;}
};
int k, n, m, dis[MM][202];
vector<edge> adj[MM];
priority_queue<edge, vector<edge>, greater<edge>> q;
int main(){
    scanf("%d%d%d", &k, &n, &m);
    for (int i=0; i<m; i++){
        int a, b, t, h;
        scanf("%d%d%d%d", &a, &b, &t, &h);
        adj[a].push_back(edge(b, t, h));
        adj[b].push_back(edge(a, t, h));
    }
    int start, end; scanf("%d%d", &start, &end);
    memset(dis, 0x3f, sizeof(dis));
    dis[start][0] = 0;
    q.push(edge(start, 0, 0));
    while (!q.empty()){
        int cur = q.top().dest, mins = q.top().mins, hull = q.top().hull;
        q.pop();
        if (mins>dis[cur][hull]) continue;
        for (edge& e: adj[cur]){
            int nxt = e.dest, w = e.mins, h = e.hull;
            if (h+hull>=k) continue;
            if (dis[nxt][h+hull]>mins+w){
                dis[nxt][h+hull] = mins+w;
                q.push(edge(nxt, dis[nxt][h+hull], h+hull));
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i=0; i<k; i++) ans = min(ans, dis[end][i]);
    printf("%d\n", (ans==0x3f3f3f3f?-1:ans));

    return 0;
}