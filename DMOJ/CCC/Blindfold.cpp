// CCC '02 S3 - Blindfold

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

int r, c, m, dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1}; // u, r, d, l
char arr[380][85], path[30000];

void solve(int x, int y, int dir){
    for (int i=0; i<m; i++){
        if (path[i]=='F'){
            if (x+dx[dir]>0 && x+dx[dir]<=r && y+dy[dir]>0 && y+dy[dir]<=c){
                if (arr[x+dx[dir]][y+dy[dir]]!='X'){x+=dx[dir]; y+=dy[dir];}
                else return;
            } else return;
        } else if (path[i]=='R'){dir++; dir%=4;}
        else {dir--; if (dir==-1) dir=3;}
    }
    arr[x][y]='*';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> r >> c;
    for (int i=1; i<=r; i++){
        for (int j=1; j<=c; j++) cin >> arr[i][j];
    }
    cin >> m;
    for (int i=0; i<m; i++) cin >> path[i];
    for (int i=1; i<=r; i++){
        for (int j=1; j<=c; j++){
            if (arr[i][j]!='X'){
                for (int dir=0; dir<4; dir++) solve(i,j,dir);
            }
        }
    }
    for (int i=1; i<=r; i++){
        for (int j=1; j<=c; j++) cout << arr[i][j];
        cout << nl;
    }

    return 0;
}