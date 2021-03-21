// CCO '12 P2 - The Hungary Games

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;
#define INF 0x3f3f3f3f
using pii = pair<int, int>;

const int MM = 2e4+4;
int n, m, dis1[MM], dis2[MM];
bool inque[MM];
vector<pii> adj[MM];
deque<int> q;
int main(){
    sc(n); sc(m);
    for (int i=0; i<m; i++){
        int a, b, w; sc(a); sc(b); sc(w);
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }
    
    // run spfa from 1
    q.push_back(1);
    memset(dis1, INF, sizeof(dis1));
    dis1[1] = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop_front();
        inque[cur] = false;
        for (pii e: adj[cur]){
            int nxt = e.second, w = e.first;
            if (dis1[cur]+w<dis1[nxt]){
                dis1[nxt] = dis1[cur]+w;
                if (!inque[nxt]){
                    inque[nxt] = true;
                    q.push_back(nxt);
                }
            }
        }
    }

    // run spfa from n
    q.push_back(n);
    memset(dis2, INF, sizeof(dis2));
    memset(inque, false, sizeof(inque));
    dis2[n] = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop_front();
        inque[cur] = false;
        for (pii e: adj[cur]){
            int nxt = e.second, w = e.first;
            if (dis2[cur]+w<dis2[nxt]){
                dis2[nxt] = dis2[cur]+w;
                if (!inque[nxt]){
                    inque[nxt] = true;
                    q.push_back(nxt);
                }
            }
        }
    }

    int mindis = dis1[n], second = INT_MAX;
    for (int i=1; i<=n; i++){
        for (pii edge: adj[i]){
            int dis = dis1[i] + edge.first + dis2[edge.second];
            if (dis!=mindis && dis<second) second = dis;
        }
    }
    if (second==INF) second = -1;
    
    printf("%d\n", second);

    return 0;
}