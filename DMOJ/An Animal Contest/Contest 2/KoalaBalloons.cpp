// An Animal Contest 2 P3 - Koala Balloons

#include<bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
typedef pair<int, int> pii;
#define watch(x) cout << (#x) << ": " << x << '\n'

const int MM = 1501;
int n, m, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
bool arr[MM][MM], vis[MM][MM];
bool fit(int curx, int cury, int x){
    x--;
    if (vis[curx][cury]) return false;
    if (curx <= 0 || cury <= 0) return false;
    if (curx + x > n || cury + x > m) return false;
    for (int i=0; i<=x; i++){
        if (arr[curx+i][cury] || arr[curx+i][cury+x]) return false;
        if (arr[curx][cury+i] || arr[curx+x][cury+i]) return false;
    }
    return true;
}
bool bfs(int x){
    cout << "bfs\n";
    if (!fit(1, 1, x)) return false;
    deque<pii> q = {{1, 1}};
    memset(vis, false, sizeof(vis));
    vis[1][1] = true;
    while (!q.empty()){
        pii cur = q.front();
        q.pop_front();
        //printf("(%d, %d)\n", cur.first, cur.second);
        for (int i=0; i<4; i++){
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if (fit(nx, ny, x)){
                q.emplace_back(nx, ny);
                vis[nx][ny] = true;
            }
        }
    }
    return vis[n-x+1][m-x+1];
}
int main(){
    su(n); su(m);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            char c; sc(c);
            arr[i][j] = (c == 'X');
        }
    }
    int lo = 1, hi = min(n, m), ans = 1;
    while (lo <= hi){
        int mid = (lo + hi) / 2;
        cout << mid << '\n';
        if (bfs(mid)){
            cout << "check\n";
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    printf("%d\n", ans);
    //cout << bfs(3) << '\n';

    return 0;
}