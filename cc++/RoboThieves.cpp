// CCC '18 S3 - RoboThieves

#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define row first
#define col second
using pii = pair<int, int>;

int n, m, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, dis[105][105];
char arr[105][105];
bool inque[105][105];
pii conveyor[105][105];
deque<pii> q, cams, convs;
int is_conveyor(char c){
    if (c=='U') return 1;
    if (c=='D') return 0;
    if (c=='L') return 3;
    if (c=='R') return 2;
    return -1;
}
bool vis(char c){return (c=='W' || c=='C');}
pii conv_dfs(int r, int c, pii start){
    int dir = is_conveyor(arr[r][c]);
    if (dir==-1){
        return {r, c};
    }
    else {
        conveyor[r][c] = conv_dfs(r+dx[dir], c+dy[dir], start);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // input
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            char c; cin >> c;
            arr[i][j] = c;
            if (c=='C') cams.push_back({i, j});
            else if (is_conveyor(c)) conv_dfs(i, j);
            else if (c=='S') q.push_back({i, j});
        }
    }
    // cameras
    while (!cams.empty()){
        pii cam = cams.front();
        cams.pop_front();
        // vis[cam.row][cam.col] = true;
        for (int x=cam.row; x<=n; x++){
            if (arr[x][cam.col]=='W') break;
            else if (is_conveyor(arr[x][cam.col])==-1) arr[x][cam.col] = 'C';
        }
        for (int x=cam.row; x>=1; x--){
            if (arr[x][cam.col]=='W') break;
            else if (is_conveyor(arr[x][cam.col])==-1) arr[x][cam.col] = 'C';
        }
        for (int y=cam.col; y<=n; y++){
            if (arr[cam.row][y]=='W') break;
            else if (is_conveyor(arr[cam.row][y])==-1) arr[cam.row][y] = 'C';
        }
        for (int y=cam.col; y>=1; y--){
            if (arr[cam.row][y]=='W') break;
            else if (is_conveyor(arr[cam.row][y])==-1) arr[cam.row][y] = 'C';
        }
    }
    
    // spfa
    memset(dis, INF, sizeof(dis));
    dis[q.front().row][q.front().col] = 0;
    while (!q.empty()){
        pii cur = q.front();
        q.pop_front();
        inque[cur.row][cur.col] = false;
        for (int i=0; i<4; i++){
            if (!vis(arr[cur.row+dx[i]][cur.col+dy[i]])){
                if (dis[cur.row+dx[i]][cur.col+dy[i]]>dis[cur.row][cur.col]+1){
                    dis[cur.row+dx[i]][cur.col+dy[i]] = dis[cur.row][cur.col]+1;
                    if (!inque[cur.row+dx[i]][cur.col+dy[i]]){
                        inque[cur.row+dx[i]][cur.col+dy[i]] = true;
                        q.push_back({cur.row+dx[i], cur.col+dy[i]});
                    }
                }
            }
        }
    }

    return 0;
}
