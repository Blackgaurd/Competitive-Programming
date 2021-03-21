// CCO '15 P2 - Artskjid

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;
#define INF 0x3f3f3f3f
using pii = pair<int, int>;

const int MM = 20;
int n, m, dis[MM], pre[MM];
bool inque[MM];
vector<pii> adj[MM];
deque<int> q;
bool trace(int cur, int nxt){
    for (int i=pre[cur]; i!=-1; i=pre[i]){
        if (i==nxt) return false;
    }
    return true;
}
int main(){
    sc(n); sc(m);
    for (int i=0; i<m; i++){
        int a, b, w; sc(a); sc(b); sc(w);
        adj[a].push_back({w, b});
    }
    q.push_back(0);
    pre[0] = -1;
    while (!q.empty()){
        int cur = q.front();
        q.pop_front();
        inque[cur] = false;
        if (cur==n-1) continue;
        for (pii e: adj[cur]){
            int nxt = e.second, w = e.first;
            if (dis[cur]+w>dis[nxt]){
                if (trace(cur, nxt)){
                    pre[nxt] = cur;
                    dis[nxt] = dis[cur]+w;
                    if (!inque[nxt]){
                        inque[nxt] = true;
                        q.push_back(nxt);
                    }
                }
            }
        }
    }
    cout << dis[n-1] << '\n';

    return 0;
}