// Mynerva

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;
using pii = pair<int, int>;
#define ms(arr, val) memset(arr, val, sizeof(arr))

const int MM = 5e5+5;
int n, m, qq, bright[MM], dark[MM];
short dis[MM];
vector<pii> adj[MM];
int main(){
    sc(n); sc(m);
    for (int i=0; i<m; i++){
        int a, b, c; sc(a); sc(b); sc(c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    deque<int> q = {1};
    ms(dis, -1);
    dis[1] = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop_front();
        for (pii e: adj[cur]){
            int nxt = e.first;
            int col = e.second;
            if (dis[nxt]==-1){
                dis[nxt] = dis[cur]+1;
                bright[nxt] = bright[cur]+col;
                dark[nxt] = dark[cur]+col;
                q.push_back(nxt);
            }
            else if (dis[nxt]==dis[cur]+1){
                bright[nxt] = max(bright[nxt], bright[cur]+col);
                dark[nxt] = min(dark[nxt], dark[cur]+col);
                q.push_back(nxt);
            }
        }
    }
    sc(qq);
    while (qq--){
        int a; sc(a);
        string col; cin >> col;
        cout << dis[a] << ' ';
        if (col[0]=='W') cout << bright[a] << '\n';
        else cout << dark[a] << '\n';
    }
    

    return 0;
}