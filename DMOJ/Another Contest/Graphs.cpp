// Another Contest 1 Problem 2 - Graphs

#include<bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;
typedef pair<int, int> pii;

const int MM = 1e5+3;
int n, m, qq, p[MM], dis[MM];
vector<int> adj[MM];
int flead(int __x){
    if (p[__x]!=__x) p[__x] = flead(p[__x]);
    return p[__x];
}
int bfs(int a, int b){
    deque<pii> q = {{a, 0}, {b, 0}};
    memset(dis, -1, sizeof(dis));
    dis[a] = dis[b] = 0;
    while (!q.empty()){
        int cur = q.front().first, par = q.front().second;
        q.pop_front();
        for (int nxt: adj[cur]){
            if (dis[nxt] == -1){
                dis[nxt] = dis[cur] + 1;
                q.push_back({nxt, cur});
            }
            else if (nxt != par) return dis[cur] + dis[nxt] + 1;
        }
    }
    return -123;
}
int main(){
    su(n); su(m); su(qq);
    for (int i=1; i<=n; i++) p[i] = i;
    while (m--){
        int a, b; su(a); su(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        if (flead(a) != flead(b)){
            p[flead(a)] = flead(b);
        }
    }
    while (qq--){
        int a, b; su(a); su(b);
        if (flead(a) != flead(b)) printf("-1\n");
        else printf("%d\n", bfs(a, b));
    }

    return 0;
}
