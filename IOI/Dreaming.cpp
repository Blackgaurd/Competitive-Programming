// IOI '13 P1 - Dreaming

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define ms(arr, val) memset(arr, val, sizeof(arr))

const int MM = 1e5;
int p[MM], dis1[MM], dis2[MM], ans = 0;
vector<pii> adj[MM];
vector<int> radii;
unordered_map<int, vector<int>> trees;
bool vis[MM];
int flead(int x){
    if (p[x]!=x) p[x] = flead(p[x]);
    return p[x];
}
int bfs(int start, int (&dis)[MM], vector<int> curtree){
    deque<int> q = {start};
    dis[start] = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop_front();
        curtree.push_back(cur);
        for (pii e: adj[cur]){
            int nxt = e.first, w = e.second;
            if (dis[nxt]==-1){
                dis[nxt] = dis[cur]+w;
                q.push_back(nxt);
            }
        }
    }

    int maxdis = -1, furthest = 0;
    for (int node: curtree){
        if (dis[node]>maxdis){
            maxdis = dis[node];
            furthest = node;
        }
    }
    ans = max(ans, maxdis);

    return furthest;
}
int frad(vector<int> curtree){
    if (curtree.size() == 1) return 0;
    int end1 = bfs(curtree[0], dis1, curtree);
    int end2 = bfs(end1, dis2, curtree);
    ms(dis1, -1);
    bfs(end2, dis1, curtree);
    
    int rad = INT_MAX;
    for (int node: curtree){
        rad = min(rad, max(dis1[node], dis2[node]));
    }
    return rad;
}
int travelTime(int N, int M, int L, int A[], int B[], int T[]){
    for (int i=0; i<N; i++) p[i] = i;
    for (int i=0; i<M; i++){
        adj[A[i]].push_back({B[i], T[i]});
        adj[B[i]].push_back({A[i], T[i]});
        if (flead(A[i]) != flead(B[i])){
            p[flead(A[i])] = flead(B[i]);
        }
    }
    for (int i=0; i<N; i++){
        trees[flead(i)].push_back(i);
    }
    ms(dis1, -1); ms(dis2, -1);
    for (auto tree: trees){
        radii.push_back(frad(tree.second));
    }
    sort(radii.begin(), radii.end(), greater<>());

    if (radii.size()>1){
        ans = max(ans, radii[0] + radii[1] + L);
        if (radii.size()>2){
            ans = max(ans, radii[1] + radii[2] + 2*L);
        }
    }
    return ans;
}
