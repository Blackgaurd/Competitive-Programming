// CCC '99 S4 - A Knightly Pursuit

#include<bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define nl '\n'

int n, dx[] = {-1, 1, 2, 2, 1, -1, -2, -2}, dy[] = {-2, -2, -1, 1, 2, 2, 1, -1};
pair<string, int> solve(int r, int c, int pr, int pc, int kr, int kc){
    bool vis[101][101];
    int dis[101][101];
    dis[kr][kc] = 0;
    deque<pair<int, int>> q;
    q.push_back({kr, kc});
    while (!q.empty()){
        int curx = q.front().first, cury = q.front().second;
        q.pop_front();
        vis[curx][cury] = true;
        cout << curx << " " << cury << nl;
        for (int i=0; i<8; i++){
            if (curx+dx[i]>=1 && curx+dx[i]<=r && cury+dy[i]>=1 && cury+dy[i]<=c){
                if (!vis[curx+dx[i]][cury+dy[i]]){
                    q.push_back({curx+dx[i], cury+dy[i]});
                    dis[curx+dx[i]][cury+dy[i]] = dis[curx][cury]+1;
                }
            }
        }
    }
    //dis[pr][pc] = -1;
    for (int i=1; i<=r; i++){
        for (int j=1; j<=c; j++) cout << dis[i][j] << ' ';
        cout << nl;
    }

    // pawn moves first
    // 0 = lose, 1 = stalemate, 2 = win
    int kmoves = 0;
    while (pr<=r){
        pr++;
        kmoves++;
        if (dis[kr][kc]==kmoves){
            return {"Win", kmoves};
        }
        else if (dis[kr+1][kc]==kmoves){
            return {"Stalemate", kmoves};
        }
    }
    return {"Loss", kmoves};

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scan(n);
    while (n--){
        int r, c, pr, pc, kr, kc;
        scan(r); scan(c); scan(pr); scan(pc); scan(kr); scan(kc);
        pair<string, int> sol = solve(r, c, pr, pc, kr, kc);
        cout << sol.first << " " << sol.second << nl;
    }
}