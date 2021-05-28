// CCC '09 S4 - Shop and Ship
// using SPFA

#include<bits/stdc++.h>
using namespace std;

const int MM = 5e3+3;
int n, t, k, d, dis[MM], ans = INT_MAX;
bool inque[MM];
vector<pair<int, int>> adj[MM];
unordered_map<int, int> pencils;
int main(){
    scanf("%d%d", &n, &t);
    for (int i=0; i<t; i++){
        int a, b, w; scanf("%d%d%d", &a, &b, &w);
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }
    scanf("%d", &k);
    for (int i=0; i<k; i++){
        int a, p; scanf("%d%d", &a, &p);
        pencils.insert({a, p});
    }
    scanf("%d", &d);
    memset(dis, 0x3f, sizeof(dis));
    deque<int> q;
    q.push_back(d); dis[d] = 0; inque[d] = true;
    while (!q.empty()){
        int cur = q.front();
        q.pop_front();
        inque[cur] = false;
        for (auto p: adj[cur]){
            int w = p.first, nxt = p.second;
            if (dis[nxt]>dis[cur]+w){
                dis[nxt] = dis[cur]+w;
                if (!inque[nxt]){
                    inque[nxt] = true;
                    q.push_back(nxt);
                }
            }
        }
        // slf
        if (q.back()<cur){
            q.push_front(q.back());
            q.pop_back();
        }
        if (pencils[cur]){
            ans = min(ans, dis[cur]+pencils[cur]);
        }
    }
    printf("%d\n", ans);


    return 0;
}