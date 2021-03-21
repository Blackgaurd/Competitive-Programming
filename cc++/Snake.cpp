// LCC/Moose '20 Contest 3 S3 - Snake

#include<bits/stdc++.h>
using namespace std;

int n, m, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1}, _empty = 0;
char arr[6][6];
bool vis[6][6], eat = false;
bool check(){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (!vis[i][j]) return false;
        }
    }
    eat = true;
    return true;
}
void dfs(int x, int y){
    vis[x][y] = true;
    for (int i=0; i<4; i++){
        if (x+dx[i]>=0 && x+dx[i]<n){
            if (y+dy[i]>=0 && y+dy[i]<m){
                if (!vis[x+dx[i]][y+dy[i]]) dfs(x+dx[i], y+dy[i]);
                if (check()) return;
            }
        }
    }
    vis[x][y] = false;
}   
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> arr[i][j];
            if (arr[i][j]=='#') vis[i][j] = true;
            else _empty++;
        }
    }
    if (_empty == 0){
        cout << "Sadge.\n";
        return 0;
    }
    if (_empty==1){
        cout << "Chomp!\n";
        return 0;
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (!vis[i][j] && !eat){
                dfs(i, j);
            }
        }
    }
    cout << (eat? "Chomp!":"Sadge.") << '\n';

    return 0;
}