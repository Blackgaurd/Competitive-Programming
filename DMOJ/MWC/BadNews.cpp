// MWC '15 #3 P3: Bad News

#include<bits/stdc++.h>
using namespace std;

int n, q;
char arr[26][26];
bool vis[26][26];
string t;
struct trp{
    int first, second, ind;
};
bool bfs(int x, int y){
    memset(vis, false, sizeof(vis));
    vis[x][y] = true;
    deque<trp> q = {{x, y, 0}};
    while (!q.empty()){
        trp cur = q.front();
        q.pop_front();
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    while (q--){
        cin >> t;

    }
    
    return 0;
}