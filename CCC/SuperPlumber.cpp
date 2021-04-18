// CCC '04 S5 - Super Plumber

#include<bits/stdc++.h>
using namespace std;
#ifndef WIN32
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

const int MM = 103;
int n, m, dp[MM][MM], dx[] = {-1, 0, 1}, dy[] = {0, 1, 0};
char arr[MM][MM];
bool vis[MM][MM];
void dfs(int curx, int cury, int prev){
    int vals[] = {-1, -1, -1};
    dp[curx][cury] += prev;
    for (int i=0; i<3; i++){
        if (curx + dx[i] <= n && curx + dx[i] >= 1){
            if (cury + dy[i] <=m && cury + dy[i] >= 1){
                if (vis[curx + dx[i]][cury + dy[i]]){
                    vals[i] = dp[curx + dx[i]][cury + dy[i]];
                }
                else if (arr[curx + dx[i]][cury + dy[i]] == '*'){
                    continue;
                }
                else {
                    int pass = (arr[curx][cury] == '.'? 0:arr[curx][cury] - '0');
                    dfs(curx + dx[i], cury + dy[i], pass);
                    vals[i] = dp[curx + dx[i]][cury + dy[i]];
                }
            }
        }
    }
    dp[curx][cury] = max({vals[0], vals[1], vals[2]});
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            sc(arr[i][j]);



    return 0;
}
