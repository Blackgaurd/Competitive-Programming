// Pools Counting

#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
int n, m, k, x, y, pools = 0;
bool vis[105][105];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i=0; i<k; i++){
        cin >> x >> y;
        vis[x][y] = true;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if (vis[i][j]){ // vis = if theres water
                pools++;
                queue<int> qx, qy;
                qx.push(i); qy.push(j);
                while (!qx.empty()){
                    int curx = qx.front(), cury = qy.front();
                    qx.pop(); qy.pop();
                    for (int i=0; i<4; i++){
                        if (vis[curx+dx[i]][cury+dy[i]]){
                            vis[curx+dx[i]][cury+dy[i]] = false;
                            qx.push(curx+dx[i]);
                            qy.push(cury+dy[i]);
                        }
                    }
                }
            }
        }
    }
    cout << pools;

    return 0;
}