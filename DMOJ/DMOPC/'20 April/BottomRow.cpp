// DMOPC '20 Contest 5 P3 - Bottom Row
// partials

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int MM = 2e3 + 3;
int n, k, dis[MM][MM], dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};
char par[MM][MM], dir[] = {'R', 'D', 'U', 'L'};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    for (int i=0; i<k; i++){
        int a, b; cin >> a >> b;
        dis[a][b] = -1;
    }
    deque<pii> q = {{1, 1}};
    dis[1][1] = 0;
    par[1][1] = 'X';
    while (!q.empty()){
        pii cur = q.front();
        q.pop_front();
        for (int i=0; i<4; i++){
            if (cur.first + dx[i] >= 1 && cur.first + dx[i] <= n && cur.second + dy[i] >= 1 && cur.second + dy[i] <= n){
                if (dis[cur.first][cur.second] + i < dis[cur.first + dx[i]][cur.second + dy[i]]){
                    dis[cur.first + dx[i]][cur.second + dy[i]] = dis[cur.first][cur.second] + i;
                    q.push_back({cur.first + dx[i], cur.second + dy[i]});
                    par[cur.first + dx[i]][cur.second + dy[i]] = dir[i];
                }
            }
        }
    }
    if (dis[n][n] == 0x3f3f3f3f) cout << "IMPOSSIBLE\n";
    else {
        string sol = "";
        int x = n, y = n;
        while (par[x][y] != 'X'){
            sol = par[x][y] + sol;
            if (par[x][y] == 'R'){
                y--;
            }
            else if (par[x][y] == 'L'){
                y++;
            }
            else if (par[x][y] == 'U'){
                x--;
            }
            else if (par[x][y] == 'D'){
                x++;
            }
        }
        cout << sol << '\n';
    }

    return 0;
}