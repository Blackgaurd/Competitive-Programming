// CCO '14 P2 - King Gruff
// run dijktra twice, calculate min distance for each edge
// sort array by distance
// psa the costs
// binary search to find values

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;
using pii = pair<int, int>;
struct edge{
    int v, w, cost;
    edge(int vv, int ww, int cc){
        v = vv;
        w = ww;
        cost = cc;
    }
};

const int MM = 1e5+5;
int n, m, a, b, qq, dis1[MM], dis2[MM];
vector<edge> adj[MM], revadj[MM];
void spfa(int start, int dis[], vector<edge> adj[]){
    fill(dis, dis+n+1, 0x3f3f3f3f);
    bool inque[MM];
    memset(inque, false, sizeof(inque));
    deque<int> q = {start};
    dis[start] = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop_front();
        inque[cur] = false;
        for (auto e: adj[cur]){
            int nxt = e.v, w = e.w;
            if (dis[cur]+w<dis[nxt]){
                dis[nxt] = dis[cur]+w;
                if (!inque[nxt]){
                    inque[nxt] = true;
                    q.push_back(nxt);
                }
            }
        }
    }
}
int main(){
    sc(n); sc(m); sc(a); sc(b);
    for (int i=0; i<m; i++){
        int u, v, w, cost;
        sc(u); sc(v); sc(w); sc(cost);
        adj[u].push_back(edge(v, w, cost));
        revadj[v].push_back(edge(u, w, cost));
    }
    spfa(a, dis1, adj);
    spfa(b, dis2, revadj);
    vector<pair<int, int>> path;
    for (int i=1; i<=n; i++){
        for (auto e: adj[i]){
            path.push_back({dis1[i] + e.w + dis2[e.v], e.cost});
        }
    }
    sort(path.begin(), path.end());
    for (int i=1; i<path.size(); i++){
        path[i].second+=path[i-1].second;
    }
    sc(qq);
    for (int i=0; i<qq; i++){
        int d; sc(d);
        int pos = upper_bound(path.begin(), path.end(), make_pair(d, 0x3f3f3f3f)) - path.begin();
        if (pos>0) cout << path[pos-1].second << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}