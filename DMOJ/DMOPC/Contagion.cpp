// DMOPC '15 Contest 3 P4 - Contagion

#include<bits/stdc++.h>
using namespace std;
#ifndef WIN32
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;
typedef pair<long long, long long> pii;

const int MM = 3003;
int n, q, start;
long long dis[MM], adj[MM][MM];
vector<pii> nodes;
bool vis[MM];
long long calc(pii a, pii b){ return pow(abs(a.first-b.first), 2) + pow(abs(a.second-b.second), 2); }
int mindis(){
    long long ret = LLONG_MAX;
    int v = -1;
    for (int i=1; i<=n; i++){
        if (!vis[i] && dis[i] < ret){
            ret = dis[i];
            v = i;
        }
    }
    return v;
}
int main(){
    su(n);
    for (int i=1; i<=n; i++){
        int a, b; su(a); su(b);
        for (int j=0; j<nodes.size(); j++)
            adj[i][j+1] = adj[j+1][i] = calc({a, b}, nodes[j]);
        nodes.push_back({a, b});
    }
    su(start);
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[start] = 0;
    for (int i=1; i<=n; i++){
        int u = mindis();
        vis[u] = true;
        for (int v=1; v<=n; v++){
            if (!adj[u][v] && !vis[v]) continue;
            if (dis[u] + adj[u][v] < dis[v])
                dis[v] = dis[u] + adj[u][v];
        }
    }
    sort(dis, dis+n+1);
    // for (int i=0; i<=n; i++) cout << i << ": " << dis[i] << '\n';
    su(q);
    while (q--){
        long long a; su(a);
        int lo = 0, hi = n-1, ans = 0;
        while (lo <= hi){
            int mid = (lo + hi) / 2;
            if (dis[mid] <= a){
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        printf("%d\n", ans+1);
    }

    return 0;
}