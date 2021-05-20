// Another Contest 1 Problem 2 - Graphs

#include<bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

const int MM = 1e5+3;
int n, m, qq, p[MM], dis1[MM], dis2[MM];
vector<int> adj[MM];
int flead(int __x){
    if (p[__x]!=__x) p[__x] = flead(p[__x]);
    return p[__x];
}
int bfs(int a, int b){
    deque<int> q1 = {a}, q2 = {b};
    memset(dis1, -1, sizeof(dis1));
    memset(dis2, -1, sizeof(dis2));
    dis1[a] = 0;
    dis2[b] = 0;
    while (!q1.empty() && !q2.empty()){
        int cur1 = q1.front(), cur2 = q2.front();
        q1.pop_front(); q2.pop_front();
        for (int nxt: adj[cur1]){
            if (dis1[nxt] == -1){
                dis1[nxt] = dis1[cur1] + 1;
                q1.push_back(nxt);
                if (dis2[nxt] != -1){
                    return dis1[nxt] + dis2[nxt];
                }
            }
        }
        for (int nxt: adj[cur2]){
            if (dis2[nxt] == -1){
                dis2[nxt] = dis2[cur2] + 1;
                q2.push_back(nxt);
                if (dis1[nxt] != -1){
                    return dis1[nxt] + dis2[nxt];
                }
            }
        }
    }
    return dis1[b];
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
        else {
            printf("%d\n", bfs(a, b));
        }
    }

    return 0;
}
