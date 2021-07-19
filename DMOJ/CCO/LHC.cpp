// CCO '13 P3 - LHC
// using dfs this time
// longest loop MUST pass through mid

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
typedef pair<int, int> pii;
typedef unsigned long long ull;
#define watch(x) cout << (#x) << ": " << x << '\n'

const int MM = 4e5+3;
int n, mid, max1 = 0, max2 = 0, in[MM], dis[MM], cnt[MM];
pii p[MM];
vector<int> adj[MM];
set<int> max1cnt, max2cnt;
pii bfs(int start){ // find furthest node from start (and how far)
    deque<int> q = {start};
    memset(dis, -1, sizeof(dis));
    dis[start] = 0;
    int ret, mxdis = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop_front();
        if (dis[cur] > mxdis){
            mxdis = dis[cur];
            ret = cur;
        }
        for (int nxt: adj[cur]){
            if (dis[nxt] == -1){
                dis[nxt] = dis[cur] + 1;
                q.push_back(nxt);
            }
        }
    }
    return {ret, mxdis};
}
void dfs(int cur, int par){
    if (in[cur] == 1){
        if (p[cur].first > max1){
            max2 = max1;
            max1 = p[cur].first;
        }
        else if (p[cur].first < max1 && p[cur].first > max2)
            max2 = p[cur].first;
    }

    for (int nxt: adj[cur]){
        if (nxt != par){
            p[nxt] = {p[cur].first + 1, p[cur].second};
            dfs(nxt, cur);
        }
    }
}
int main(){
    su(n);
    for (int i=1; i<n; i++){
        int a, b; su(a); su(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        in[a]++; in[b]++;
    }

    // find diameter
    int e1 = bfs(1).first;
    pii de = bfs(e1);
    int e2 = de.first, dia = de.second;

    // find midpoint
    for (int i=1; i<=n; i++){
        if (dis[i] == dia/2){
            mid = i;
            break;
        }
    }

    // group end nodes
    for (int i=1; i<=adj[mid].size(); i++){
        int nxt = adj[mid][i-1];
        p[nxt] = {1, i};
        dfs(nxt, mid);
    }

    for (int i=1; i<=n; i++){
        if (in[i] == 1){
            if (p[i].first == max1){
                max1cnt.insert(p[i].second);
                cnt[p[i].second]++;
            }
            else if (p[i].first == max2){
                max2cnt.insert(p[i].second);
                cnt[p[i].second]++;
            }
        }
    }

    ull ans = 0;
    watch(mid);
    if (dia & 1){
        // something flawed with odd case
        /* 1 2
        2 8
        2 9
        4 10
        4 1
        4 12
        1 3
        1 5
        5 6
        5 7
        6 13
        7 14
        7 15
        7 16
        7 11 */
        // there can only be one branch of max1 (otherwise dia will be even)
        ull max2sum = 0;
        for (int i: max2cnt) max2sum += cnt[i];
        for (int i: max1cnt)
            ans = max2sum * cnt[i];
    }
    else {
        vector<int> nums;
        ull max1sum = 0;
        for (int i: max1cnt){
            nums.push_back(cnt[i]);
            max1sum += cnt[i];
        }
        for (int i: nums){
            max1sum -= i;
            ans += max1sum * i;
        }
    }
    printf("%d %llu\n", dia + 1, ans);

    return 0;
}
