// DMOPC '19 Contest 2 P2 - Squares

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 503;
int n, m, arr[MM][MM], d[2][2] = {{1, 0}, {0, 1}};
ll dis[MM][MM];
bool inque[MM][MM];
deque<pii> q;
int main(){
    su(n); su(m);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            su(arr[i][j]);
            dis[i][j] = LLONG_MAX;
        }
    }

    dis[1][1] = arr[1][1];
    q.emplace_back(1, 1);
    while (!q.empty()){
        int curx = q.front().first, cury = q.front().second;
        q.pop_front();
        inque[curx][cury] = false;
        for (int i=0; i<2; i++){
            int nx = curx + d[i][0], ny = cury + d[i][1];
            if (nx > n || ny > m) continue;
            if (dis[curx][cury] + arr[nx][ny] < dis[nx][ny]){
                dis[nx][ny] = dis[curx][cury] + arr[nx][ny];
                if (!inque[nx][ny]){
                    inque[nx][ny] = true;
                    q.emplace_back(nx, ny);
                }
            }
        }
    }

    printf("%lld\n", dis[n][m]);

    return 0;
}