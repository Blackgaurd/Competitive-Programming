// DWITE '12 R1 #5 - Haunted House

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ms memset
#define pb push_back
#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = deque<int>;

int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    /*
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    for (int k=0; k<1; k++){
        int n, sx, sy, candies = 0; cin >> n;
        int arr[10][10] = {{0}}, dis[10][10] = {{0}};
        bool vis[10][10];
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                char c; cin >> c;
                if (c=='.') {continue;}
                else if (c=='B'){sx = i; sy = j;}
                else if (c=='#') arr[i][j] = 27;
                else if (c=='*') arr[i][j] = 28;
                else arr[i][j] = (int)(c-'a'+1);
            }
        }
        deque<pii> q;
        q.pb(make_pair(sx, sy));
        vis[sx][sy] = true;
        while (!q.empty()){
            pii cur = q.front();
            for (int i=0; i<4; i++){
                if (cur.first+dx[i]>=0 && cur.first+dx[i]<n && cur.second+dy[i]>=0 && cur.second+dy[i]<n){
                    if (!vis[cur.first+dx[i]][cur.second+dy[i]] && candies>=arr[cur.first+dx[i]][cur.second+dy[i]]){
                        if (arr[cur.first+dx[i]][cur.second+dy[i]] = 28) candies++;
                        vis[cur.first+dx[i]][cur.second+dy[i]] = true;
                        dis[cur.first+dx[i]][cur.second+dy[i]] = dis[cur.first][cur.second]+1;
                    }
                }
            }
        }
        

    }

    return 0;
}