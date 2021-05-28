// Hide n Seek

#include<bits/stdc++.h>
using namespace std;

int n, m, t, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1}, ans = INT_MAX;
char arr[21][21];
vector<pair<int, int>> hiders;
pair<int, int> start;
int bfs(pair<int, int> from, pair<int, int> to){
    deque<pair<int, int>> q;
    bool vis[21][21] = {{false}};
    int dis[21][21] = {{0}};
    q.push_back(from);
    while (!q.empty()){
        int curx = q.front().first, cury = q.front().second;
        q.pop_front();
        if (curx==to.first && cury==to.second) break; 
        vis[curx][cury] = true;
        for (int i=0; i<4; i++){
            if (curx+dx[i]>=1 && cury+dy[i]>=1 && curx+dx[i]<=n && cury+dy[i]<=m){
                if (!vis[curx+dx[i]][cury+dy[i]] && arr[curx+dx[i]][cury+dy[i]]!='X'){
                    q.push_back({curx+dx[i], cury+dy[i]});
                    dis[curx+dx[i]][cury+dy[i]] = dis[curx][cury]+1;
                }
            }
        }
    }
    return dis[to.first][to.second];
}
int find_dis(vector<pair<int, int>> order){
    int dis = bfs(start, order[0]);
    for (int i=0; i<t-1; i++){
        dis+=bfs(order[i], order[i+1]);
    }
    return dis;
}
void print(vector<pair<int, int>> p){
    for (int i=0; i<p.size()-1; i++){
        cout << '(' << p[i].first << " ," << p[i].second  << "), ";
    }
    cout << '(' << p[p.size()-1].first << ", " << p[p.size()-1].second << ')';
    cout << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> t;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            char c; cin >> c;
            arr[i][j] = c;
            if (c=='.') continue;
            if (c=='H') hiders.push_back({i, j});
            else if (c=='G') start = {i, j};
        }
    }
    sort(hiders.begin(), hiders.end());
    //print(hiders);
    ans = min(ans, find_dis(hiders));
    while (next_permutation(hiders.begin(), hiders.end())){
        //print(hiders);
        ans = min(ans, find_dis(hiders));
    }
    cout << ans << '\n';

    return 0;
}