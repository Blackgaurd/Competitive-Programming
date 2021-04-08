// Adam's Party

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int MM = 2e5+3, MD = 1e9+7;
int n, m, k, dis1[MM], dis2[MM];
vector<int> adj[MM];
ull mul_mod(ull a, ull b, ull mod=MD) {
    ull ret = 0;
    while (a > 0) {
        if (a & 1)
            if((ret += b) > mod) ret %=mod;
        a >>= 1;
        if ((b <<= 1) > mod) b %= mod;
    }
    return ret;
}

ull qpow(ull a, ull exp, ull mod=MD) {
    if (exp == 0) return 1;
    ull ret = 1;
    while (exp > 0) {
        if (exp & 1)
            ret = mul_mod(ret, a, mod);
        a = mul_mod(a, a, mod);
        exp >>= 1;
    }
    return ret;
}

void bfs(int start, int dis[]){
    deque<int> q = {start};
    dis[start] = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop_front();
        for (int nxt: adj[cur]){
            if (dis[nxt] == -1){
                dis[nxt] = dis[cur] + 1;
                q.push_back(nxt);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dis1, -1, sizeof(dis1));
    memset(dis2, -1, sizeof(dis2));
    bfs(1, dis1);
    bfs(n, dis2);
    int guests = 0;
    for (int i=1; i<=n; i++){
        if (dis1[i] != -1 && dis1[i] <= k &&
            dis2[i] != -1 && dis2[i] <= k)
            guests++;
    }
    cout << qpow(2, guests - 2) << '\n';

    return 0;
}