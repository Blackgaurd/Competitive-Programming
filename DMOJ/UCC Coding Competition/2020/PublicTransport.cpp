// UCC Coding Competition '20 P5 - Public Transport

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

const int MM = 5003;
int l, s, e, n, a, b, dis[MM];
vector<int> adj[MM];
deque<int> q;
int main(){
    su(l); su(s); su(e); su(n);
    while (n--){
        su(a); su(b);
        adj[a].push_back(b);
    }
    q.push_back(s);
    memset(dis, -1, sizeof(dis));
    dis[s] = 0;
    while (!q.empty()){
        for (int nxt: adj[q.front()]){
            if (dis[nxt] == -1){
                dis[nxt] = dis[q.front()] + 1;
                q.push_back(nxt);
            }
        }
        q.pop_front();
    }
    printf("%d\n", dis[e]);

    return 0;
}