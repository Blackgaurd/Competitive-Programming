// VM7WC '15 #4 Gold - Chain Rule

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;
using pii = pair<int, int>;

const int MM = 1e5;
int n, m, dis1[MM], dis2[MM], ans = 0;
vector<pii> adj[MM];
void spfa(int start, int (&dis)[MM]){
    deque<int> q = {start};
    bool inque[MM];
    memset(inque, false, sizeof(inque));
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[start] = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop_front();
        inque[cur] = false;
        for (pii e: adj[cur]){
            int nxt = e.second, w = e.first;
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
    sc(n); sc(m);
    for (int i=0; i<m; i++){
        int a, b, w; sc(a); sc(b); sc(w);
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }
    spfa(0, dis1);
    spfa(n-1, dis2);
    //int dia = 0;
    //for (int i=0; i<n; i++) dia = max(dia, dis1[i]);

    for (int i=0; i<n; i++){
        ans = max(ans, dis1[i]+dis2[i]);
    }
    cout << ans << '\n';


    return 0;
}