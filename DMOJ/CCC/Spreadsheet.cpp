// CCC '04 S3 - Spreadsheet

#include<bits/stdc++.h>
using namespace std;

string arr[10][10];
int val[10][10];
bool vis[10][10];
int dfs(int i, int j){
    vis[i][j] = true;
    if (arr[i][j][0] <= '9') return val[i][j] = stoi(arr[i][j]);
    string &cur = arr[i][j];
    int &ret = val[i][j]; ret = 0;
    for (int i=0; i<cur.length(); i+=3){
        int ni = cur[i] - 'A', nj = cur[i+1] - '0';
        if (vis[ni][nj]) return val[i][j] = -1;
        int nxt = dfs(ni, nj);
        if (nxt == -1) return val[i][j] = -1;
        ret += nxt;
    }
    return ret;
}
int main(){
    for (int i=0; i<10; i++){
        for (int j=1; j<=9; j++){
            cin >> arr[i][j];
        }
    }
}