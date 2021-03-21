// Bob's Video Game

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INF 0x3f3f3f3f

// dis[from][to]
int n, m, t, dis[303][303];
vector<pii> adj[303];
priority_queue<pii, vector<pii>, greater<pii>> q;
int main(){
    sc(n); sc(m); sc(t);
    for (int i=0; i<m; i++){
        int a, b, h; sc(a); sc(b); sc(h);
        adj[a].push_back({h, b});
    }
    memset(dis, -1, sizeof(dis));
    for (int i=1; i<=n; i++){
        int ans = 0;
        q.push({0, i});
        while (!q.empty()){
            int cur = q.top().second, w = q.top().first;
            q.pop();
            if (dis[i][cur]==-1){
                ans = max(ans, w);
                dis[i][cur] = ans;
                for (pii nxt: adj[cur]) q.push(nxt);
            }
        }
    }
    
    for (int i=0; i<t; i++){
        int a, b; sc(a); sc(b);
        printf("%d\n", dis[a][b]);
    }
    
    /*
    for (int i=1; i<=n; i++){
        cout << i << ": ";
        for (int j=1; j<=n; j++) cout << (dis[i][j]==-1?0:dis[i][j]) << " ";
        cout << '\n';
    }
    */

    return 0;
}