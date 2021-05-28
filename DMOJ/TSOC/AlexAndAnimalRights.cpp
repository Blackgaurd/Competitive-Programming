// Alex and Animal Rights

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define ms memset
#define pb push_back
#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll, ll>;
using qi = deque<int>;
using qpii = deque<pii>;

int r, c, sum = 0, dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
char room[35][50];
bool vis[35][50];

void bfs(int x, int y){
    qi qx, qy;
    qx.pb(x); qy.pb(y);
    vis[x][y] = true;
    while (!qx.empty()){
        int curx = qx.front(), cury = qy.front();
        qx.pop_front(); qy.pop_front();
        for (int i=0; i<4; i++){
            if (!vis[curx+dx[i]][cury+dy[i]]){
                vis[curx+dx[i]][cury+dy[i]] = true;
                qx.pb(curx+dx[i]); qy.pb(cury+dy[i]);
            }
        }
    }
}

void dfs(int x, int y){
    vis[x][y] = true;
    for (int i=0; i<4; i++){
        if (!vis[x+dx[i]][y+dy[i]]){
            dfs(x+dx[i], y+dy[i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> r >> c;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            char c; cin >> c;
            if (c=='#') vis[i][j] = true;
            room[i][j] = c;
        }
    }
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (!vis[i][j] && room[i][j]=='M'){
                // bfs or dfs
                dfs(i, j); sum++;
            }
        }
    }
    cout << sum << nl;
    return 0;
}