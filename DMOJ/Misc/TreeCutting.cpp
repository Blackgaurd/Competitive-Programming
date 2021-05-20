// Tree Cutting
// steps:
// find target tree (tallest tree that is also closest)
// run sssp to target (using height)
// keep two dis arrays, one for total height, one for dis traveled

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

int r, c, mx = 0, arr[11][11], h[11][11], dis[11][11];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
pii start, fin;
vector<pair<int, int>> all_ends;
deque<pii> q;
char a;
int main(){
    // read input
    su(r); su(c);
    for (int i=1; i<=r; i++){
        for (int j=1; j<=c; j++){
            sc(a);
            if ('1' <= a && a <= '9'){
                int h_i = a - '0';
                arr[i][j] = h_i;
                if (h_i > mx){
                    mx = h_i;
                    all_ends.clear();
                    all_ends.emplace_back(i, j);
                }
                else if (h_i == mx){
                    all_ends.emplace_back(i, j);
                }
            }
            else if (a == 'X') start = {i, j};
        }
    }

    // find target tree
    int curmin = 100;
    for (pii p: all_ends){
        int curdis = abs(start.first - p.first) + abs(start.second - p.second);
        if (curdis < curmin){
            curmin = curdis;
            fin = p;
        }
    }

    // run bfs
    q.push_back(start);
    memset(h, 0x3f3f3f3f, sizeof(h));
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    h[start.first][start.second] = 0;
    dis[start.first][start.second] = 0;
    while (!q.empty()){
        int curx = q.front().first, cury = q.front().second;
        q.pop_front();
        for (int i=0; i<4; i++){
            if (curx + dx[i] <= r && curx + dx[i] >= 1 && cury + dy[i] <= c && cury + dy[i] >= 1){
                if (h[curx][cury] + arr[curx][cury] < h[curx+dx[i]][cury+dy[i]]){
                    h[curx+dx[i]][cury+dy[i]] = h[curx][cury] + arr[curx][cury];
                    dis[curx+dx[i]][cury+dy[i]] = dis[curx][cury] + (arr[curx][cury] != 0);
                    q.emplace_back(curx+dx[i], cury+dy[i]);
                }
            }
        }
    }
    printf("%d\n", dis[fin.first][fin.second]);

    return 0;
}
