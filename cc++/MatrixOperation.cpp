// Appleby Contest '19 P5 - Matrix Operation

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

const int MM = 1500;
int n, arr[MM][MM], maxdis = 0, lvl = 0;
int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
bool vis[MM][MM];

void dfs(int x, int y){
    vis[x][y] = true;
    for (int i=0; i<4; i++){
        if (x+dx[i]>=1 && x+dx[i]<=n && y+dy[i]>=1 && y+dy[i]<=n){
            if (!vis[x+dx[i]][y+dy[i]] && arr[x+dx[i]][y+dy[i]]>arr[x][y]){
                maxdis = max(maxdis, lvl++);
                dfs(x+dx[i], y+dy[i]);
                lvl--;
                vis[x+dx[i]][y+dy[i]] = false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            dfs(i, j);
            vis[i][j] = false;
        }
    }
    cout << maxdis+1;

    return 0;
}