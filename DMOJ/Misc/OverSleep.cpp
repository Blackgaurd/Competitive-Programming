// Oversleep

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

const int MM = 1005;
int r, c, er, ec, dis[MM][MM] = {{0}}, dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
//char room[MM][MM];
bool vis[MM][MM];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    qi qx, qy;
    cin >> r >> c;
    for (int i=1; i<=r; i++){
        for (int j=1; j<=c; j++){
            char c; cin >> c;
            if (c=='X') vis[i][j] = true;
            else if (c=='s'){
                vis[i][j] = true;
                qx.pb(i); qy.pb(j);
            }
            else if (c=='e') {er = i; ec = j;}
        }
    }
    while (!qx.empty()){
        int curx = qx.front(), cury = qy.front();
        if (curx==er && cury==ec){cout << dis[curx][cury]-1; return 0;}
        qx.pop_front(); qy.pop_front();
        for (int i=0; i<4; i++){
            if (curx+dx[i]>=1 && cury+dy[i]>=1 && curx+dx[i]<=r && cury+dy[i]<=c){
                if (!vis[curx+dx[i]][cury+dy[i]]){
                    vis[curx+dx[i]][cury+dy[i]] = true;
                    qx.pb(curx+dx[i]); qy.pb(cury+dy[i]);
                    dis[curx+dx[i]][cury+dy[i]] = dis[curx][cury]+1;
                }
            }
        }
    }
    cout << -1;


    return 0;
}